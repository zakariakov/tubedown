/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditPath;
    QToolButton *toolButtonRefrech;
    QLabel *label_3;
    QLineEdit *lineEditFder;
    QToolButton *toolButtonFolder;
    QLabel *labelInfo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonErr;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEditReadErr;
    QListWidget *listWidgetResult;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButtonDownload;
    QToolButton *toolButtonStop;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEditDownload;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(560, 523);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 6, 6, 6);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditPath = new QLineEdit(page);
        lineEditPath->setObjectName(QString::fromUtf8("lineEditPath"));

        gridLayout->addWidget(lineEditPath, 0, 1, 1, 1);

        toolButtonRefrech = new QToolButton(page);
        toolButtonRefrech->setObjectName(QString::fromUtf8("toolButtonRefrech"));

        gridLayout->addWidget(toolButtonRefrech, 0, 2, 1, 1);

        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEditFder = new QLineEdit(page);
        lineEditFder->setObjectName(QString::fromUtf8("lineEditFder"));

        gridLayout->addWidget(lineEditFder, 1, 1, 1, 1);

        toolButtonFolder = new QToolButton(page);
        toolButtonFolder->setObjectName(QString::fromUtf8("toolButtonFolder"));

        gridLayout->addWidget(toolButtonFolder, 1, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        labelInfo = new QLabel(page);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelInfo->sizePolicy().hasHeightForWidth());
        labelInfo->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(labelInfo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonErr = new QPushButton(page);
        pushButtonErr->setObjectName(QString::fromUtf8("pushButtonErr"));
        pushButtonErr->setCheckable(true);

        horizontalLayout_2->addWidget(pushButtonErr);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_2);

        textEditReadErr = new QTextEdit(page);
        textEditReadErr->setObjectName(QString::fromUtf8("textEditReadErr"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEditReadErr->sizePolicy().hasHeightForWidth());
        textEditReadErr->setSizePolicy(sizePolicy1);
        textEditReadErr->setMinimumSize(QSize(0, 50));
        textEditReadErr->setMaximumSize(QSize(16777215, 50));

        verticalLayout_5->addWidget(textEditReadErr);

        listWidgetResult = new QListWidget(page);
        listWidgetResult->setObjectName(QString::fromUtf8("listWidgetResult"));

        verticalLayout_5->addWidget(listWidgetResult);

        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 2, 3);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButtonDownload = new QToolButton(widget);
        toolButtonDownload->setObjectName(QString::fromUtf8("toolButtonDownload"));
        toolButtonDownload->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButtonDownload->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(toolButtonDownload);

        toolButtonStop = new QToolButton(widget);
        toolButtonStop->setObjectName(QString::fromUtf8("toolButtonStop"));
        toolButtonStop->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButtonStop->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(toolButtonStop);

        horizontalSpacer_2 = new QSpacerItem(326, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        textEditDownload = new QTextEdit(widget);
        textEditDownload->setObjectName(QString::fromUtf8("textEditDownload"));
        textEditDownload->setMaximumSize(QSize(16777215, 130));
        textEditDownload->setStyleSheet(QString::fromUtf8("background:palette(highlight);\n"
"color:palette(highlighted-text );"));
        textEditDownload->setFrameShape(QFrame::NoFrame);
        textEditDownload->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(textEditDownload);


        verticalLayout_5->addWidget(widget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Link", nullptr));
        toolButtonRefrech->setText(QCoreApplication::translate("Widget", "Get Links", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Folder", nullptr));
        toolButtonFolder->setText(QCoreApplication::translate("Widget", "Folder", nullptr));
        labelInfo->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        pushButtonErr->setText(QCoreApplication::translate("Widget", "Show Errors", nullptr));
        toolButtonDownload->setText(QCoreApplication::translate("Widget", "Download", nullptr));
        toolButtonStop->setText(QCoreApplication::translate("Widget", "Stop", nullptr));
        textEditDownload->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
