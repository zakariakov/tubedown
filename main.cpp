#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("tubedown");
    a.setApplicationName("tubedown");
    a.setApplicationDisplayName("Tubedown");
a.setWindowIcon(QIcon::fromTheme("youtube-dl",QIcon(":/images/tubedown")));

    Widget w;
    w.show();

    return a.exec();
}
