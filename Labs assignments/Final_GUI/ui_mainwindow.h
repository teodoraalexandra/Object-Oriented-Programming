#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowUI
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *memoryButton;
    QPushButton *fileButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowUI)
    {
        if (MainWindowUI->objectName().isEmpty())
            MainWindowUI->setObjectName(QStringLiteral("MainWindowUI"));
        MainWindowUI->resize(325, 164);
        centralWidget = new QWidget(MainWindowUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 283, 90));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        memoryButton = new QPushButton(layoutWidget);
        memoryButton->setObjectName(QStringLiteral("MemoryButton"));
        QFont font;
        font.setPointSize(20);
        memoryButton->setFont(font);

        verticalLayout->addWidget(memoryButton);

        fileButton = new QPushButton(layoutWidget);
        fileButton->setObjectName(QStringLiteral("FileButton"));
        fileButton->setFont(font);

        verticalLayout->addWidget(fileButton);

        MainWindowUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 325, 21));
        MainWindowUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowUI->setStatusBar(statusBar);

        retranslateUi(MainWindowUI);

        QMetaObject::connectSlotsByName(MainWindowUI);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowUI)
    {
        MainWindowUI->setWindowTitle(QApplication::translate("MainWindowUI", "MainWindow", nullptr));
        memoryButton->setText(QApplication::translate("MainWindowUI", "From memory", nullptr));
        fileButton->setText(QApplication::translate("MainWindowUI", "From text-file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowUI: public Ui_MainWindowUI {};
} // namespace Ui

QT_END_NAMESPACE


#endif // UI_MAINWINDOW_H
