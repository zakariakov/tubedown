#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>
#include <QDir>
#include <QMessageBox>
#include <QStyle>
#include <QFileDialog>
#include <QSettings>

Widget::Widget(QWidget *parent) :
    QDialog(parent)
{
    setupMe();
    
    m_process=new QProcess;
    
    m_processDownLoad=new QProcess;
       
    connect(m_process,SIGNAL(readyReadStandardOutput()),this,SLOT(ReadStandardOutput()));
    
    connect(m_process,SIGNAL(readyReadStandardError()),this,SLOT(ReadStandardError()));
    
    connect(m_process,SIGNAL(finished(int , QProcess::ExitStatus )),this,SLOT(statuFinished(int , QProcess::ExitStatus )));
    
    connect(m_processDownLoad,SIGNAL(readyReadStandardOutput()),this,SLOT(ReadStandardOutputDown()));
    
    connect(m_processDownLoad,SIGNAL(readyReadStandardError()),this,SLOT(ReadStandardErrorDown()));
    
    connect(m_processDownLoad,SIGNAL(finished(int , QProcess::ExitStatus )),this,SLOT(statuFinishedDown(int , QProcess::ExitStatus )));
    
    connect(toolButtonRefrech,SIGNAL(clicked()),this,SLOT(on_toolButtonRefrech_clicked()));
    
    connect(pushButtonErr,SIGNAL(clicked(bool)),this,SLOT(on_pushButtonErr_clicked(bool)));
    
    connect(listWidgetResult,SIGNAL(itemChanged(QListWidgetItem *)),this,SLOT(on_listWidgetResult_itemChanged(QListWidgetItem *)));
    
    connect(lineEditPath,SIGNAL(returnPressed()),this,SLOT(on_lineEditPath_returnPressed()));
    
    connect(toolButtonDownload,SIGNAL(clicked()),this,SLOT(on_toolButtonDownload_clicked()));
    
    connect(toolButtonStop,SIGNAL(clicked()),this,SLOT(on_toolButtonStop_clicked()));
    
    connect(toolButtonFolder,SIGNAL(clicked()),this,SLOT(on_toolButtonFolder_clicked()));
    
   QSettings s;
   lineEditPath->setText(s.value("Path").toString());
   lineEditFolder->setText(s.value("Folder").toString());
}

Widget::~Widget()
{
    QSettings s;

    s.setValue("Path",lineEditPath->text());
     s.setValue("Folder",lineEditFolder->text());
}


/*---------------------- Start m_process ---------------------*/
void Widget::beginReadInfo()
{
    if(lineEditPath->text().isEmpty()) return;
    m_path=lineEditPath->text();
    
    listWidgetResult->clear();
    labelInfo->clear();
    textEditReadErr->clear();
    textEditDownload->clear();
    
    QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    //    QString path=lineEditPath->text();
    QStringList list;
    list<<"-F"<<m_path;
    m_process->start("youtube-dl",list);
    
}

//---------------------------------------------------------------------------------//
void Widget::ReadStandardOutput()
{
    
    QString result=m_process->readAllStandardOutput();
    labelInfo->setText(result);
    QStringList list=result.split("\n");
    
    foreach (QString line, list) {
        if(line.isEmpty())continue;
        bool ok;
        QString begin=line.section(" ",0,1).trimmed();
        int d=begin.toInt(&ok);
        if(ok){
            QListWidgetItem *item=new QListWidgetItem(listWidgetResult);
            item->setData(Qt::UserRole,d);
            item->setText(line.remove(begin).trimmed());
            item->setCheckState(Qt::Unchecked);
        }
        listWidgetResult->sortItems();
        
    }
    if(listWidgetResult->count()>0)
    {
        toolButtonDownload->setEnabled(true);
    }
    
}

//---------------------------------------------------------------------------------//
void Widget::ReadStandardError()
{
    
    textEditReadErr->setText(m_process->readAllStandardError());
    
    //toolButtonDownload->setEnabled(false);
}

//---------------------------------------------------------------------------------//
void Widget::statuFinished(int f, QProcess::ExitStatus statu)
{
    qDebug()<<"statuFinished"<< f << statu;
    
    switch (statu) {
    case QProcess::NormalExit:
        qDebug()<<"statuFinished"<< f << statu;
        pushButtonErr->setChecked(false);
        
        break;
        
    case QProcess::CrashExit:
        qDebug()<<"statuFinished"<< f << statu;
        pushButtonErr->setChecked(true);
        break;
        
        
    }
    QGuiApplication::restoreOverrideCursor();
    
    labelInfo->clear();
}

/*--------------------- End m_process ---------------------*/

/*---------------------- m_processDownLoad ---------------------*/
void Widget::startDownload(QString id)
{
    
    QString folder=lineEditFolder->text();
    if(folder.isEmpty())
        folder=QDir::homePath();
    
    m_processDownLoad->setWorkingDirectory(folder);
    m_processDownLoad->start("youtube-dl",QStringList()<<"-f"<<id<<m_path);
    QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
}

//---------------------------------------------------------------------------------//
void Widget::ReadStandardOutputDown()
{
    
    textEditDownload->setText(m_processDownLoad->readAllStandardOutput());
    QApplication::processEvents();
}

//---------------------------------------------------------------------------------//
void Widget::ReadStandardErrorDown()
{
    
    textEditDownload->setText(m_processDownLoad->readAllStandardError());
    QApplication::processEvents();
}

//---------------------------------------------------------------------------------//
void Widget::statuFinishedDown(int f, QProcess::ExitStatus statu)
{
    qDebug()<<"statuFinished"<< f << statu;
    
    switch (statu) {
    case QProcess::NormalExit:
        qDebug()<<"statuFinished"<< f << statu;
        QMessageBox::information(this,"",tr("Finished ")+"Process::NormalExit");
        
        break;
        
    case QProcess::CrashExit:
        qDebug()<<"statuFinished"<< f << statu;
        QMessageBox::critical(this,"",tr("Finished ")+"Process::CrashExit");
        break;
        
        
    }
    
    QGuiApplication::restoreOverrideCursor();
    
    
}

/*--------------------- End m_processDownLoad  ---------------------*/

//---------------------------------------------------------------------------------//
void Widget::on_pushButtonErr_clicked(bool checked)
{
    textEditReadErr->setVisible(checked);
    
}

//---------------------------------------------------------------------------------//
void Widget::on_listWidgetResult_itemChanged(QListWidgetItem *item)
{
    qDebug()<<item->checkState()<<item->data(Qt::UserRole);
    if(item->checkState()==Qt::Checked){
        
        for (int i = 0; i < listWidgetResult->count(); ++i) {
            QListWidgetItem *it= listWidgetResult->item(i);
            if(it==item)continue;
            it->setCheckState(Qt::Unchecked);
        }
        
    }
}

//---------------------------------------------------------------------------------//
void Widget::on_lineEditPath_returnPressed()
{
    
    beginReadInfo();
    
}

//---------------------------------------------------------------------------------//
void Widget::on_toolButtonRefrech_clicked()
{
    beginReadInfo();
}

//---------------------------------------------------------------------------------//
void Widget::on_toolButtonDownload_clicked()
{
    
    QString link;
    
    for (int i = 0; i < listWidgetResult->count(); ++i) {
        QListWidgetItem *it= listWidgetResult->item(i);
        if(it->checkState()==Qt::Checked){
            link=it->data(Qt::UserRole).toString();
            
            continue;
        }
    }
    
    if(link.isEmpty()){
        QMessageBox::information(this,"",tr("Select an option to download a flile"));
        return;
    }
    textEditDownload->setVisible(true);
    //  stackedWidget->setCurrentIndex(1);
    startDownload(link);
    
}


//---------------------------------------------------------------------------------//
void Widget::on_toolButtonStop_clicked()
{
    m_processDownLoad->close();
    textEditDownload->clear();
    textEditDownload->setVisible(false);
}

//---------------------------------------------------------------------------------//
void Widget::on_toolButtonFolder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    
    if(dir.isEmpty())return;
    lineEditFolder->setText(dir);
    
}

//---------------------------------------------------------------------------------//

void Widget::setupMe()
{
    
    
    this->resize(353, 432);
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(9, 9, 9, 9);
    QGridLayout  *gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    
    QLabel *label = new QLabel(this);
    gridLayout->addWidget(label, 0, 0, 1, 1);
    
    lineEditPath = new QLineEdit(this);
    gridLayout->addWidget(lineEditPath, 0, 1, 1, 1);
    
    toolButtonRefrech = new QToolButton(this);
    gridLayout->addWidget(toolButtonRefrech, 0, 2, 1, 1);
    
    QLabel *label_3 = new QLabel(this);
    gridLayout->addWidget(label_3, 1, 0, 1, 1);
    
    lineEditFolder = new QLineEdit(this);
    gridLayout->addWidget(lineEditFolder, 1, 1, 1, 1);
    
    toolButtonFolder = new QToolButton(this);
    gridLayout->addWidget(toolButtonFolder, 1, 2, 1, 1);
    
    verticalLayout->addLayout(gridLayout);
    
    labelInfo = new QLabel(this);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelInfo->sizePolicy().hasHeightForWidth());
    labelInfo->setSizePolicy(sizePolicy);
    verticalLayout->addWidget(labelInfo);
    
    QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    
    pushButtonErr = new QPushButton(this);
    pushButtonErr->setCheckable(true);
    horizontalLayout_2->addWidget(pushButtonErr);
    
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout_2->addItem(horizontalSpacer);
    
    verticalLayout->addLayout(horizontalLayout_2);
    
    textEditReadErr = new QTextEdit(this);
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(textEditReadErr->sizePolicy().hasHeightForWidth());
    textEditReadErr->setSizePolicy(sizePolicy1);
    textEditReadErr->setMinimumSize(QSize(0, 50));
    textEditReadErr->setMaximumSize(QSize(16777215, 50));
    verticalLayout->addWidget(textEditReadErr);
    
    listWidgetResult = new QListWidget(this);
    verticalLayout->addWidget(listWidgetResult);
    
    QHBoxLayout *horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    
    toolButtonDownload = new QToolButton(this);
    toolButtonDownload->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolButtonDownload->setArrowType(Qt::NoArrow);
    horizontalLayout_3->addWidget(toolButtonDownload);
    
    toolButtonStop = new QToolButton(this);
    toolButtonStop->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolButtonStop->setArrowType(Qt::NoArrow);
    horizontalLayout_3->addWidget(toolButtonStop);
    
    QSpacerItem *horizontalSpacer_2 = new QSpacerItem(326, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout_3->addItem(horizontalSpacer_2);
    
    
    verticalLayout->addLayout(horizontalLayout_3);
    
    textEditDownload = new QTextEdit(this);
    textEditDownload->setMaximumSize(QSize(16777215, 130));
    textEditDownload->setStyleSheet(QString::fromUtf8("background:palette(highlight);\n"
                                                      "color:palette(highlighted-text );"));
    textEditDownload->setFrameShape(QFrame::NoFrame);
    textEditDownload->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
    verticalLayout->addWidget(textEditDownload);
    
    //Texte
    label->setText(tr("Link"));
    label_3->setText(tr("Folder"));
    toolButtonRefrech->setText(tr("Get Links"));
    toolButtonRefrech->setToolTip(tr("Get Links"));
    toolButtonFolder->setText(tr("Folder"));
    toolButtonFolder->setToolTip(tr("Open Folder"));
    labelInfo->setText(QString());
    pushButtonErr->setText(tr("Show Errors"));
    toolButtonDownload->setText(tr("Download"));
    toolButtonStop->setText(tr("Stop"));
    
    //Icons
    toolButtonRefrech->setIcon(QIcon((style()->standardIcon(QStyle::SP_BrowserReload))));
    toolButtonFolder->setIcon(QIcon((style()->standardIcon(QStyle::SP_DirOpenIcon))));
    toolButtonStop->setIcon(QIcon((style()->standardIcon(QStyle::SP_MediaStop))));
    toolButtonDownload->setIcon(QIcon((style()->standardIcon(QStyle::SP_DialogApplyButton))));
    pushButtonErr->setIcon(QIcon((style()->standardIcon(QStyle::SP_MessageBoxWarning))));
    
    //Visible
    textEditReadErr->setVisible(false);
    toolButtonDownload->setEnabled(false);
    textEditDownload->setVisible(false);
    
} // setupMe
