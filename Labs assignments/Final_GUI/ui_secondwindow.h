#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

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

class Ui_SecondWindowUI
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *aButton;
    QPushButton *bButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SecondWindowUI)
    {
        if (SecondWindowUI->objectName().isEmpty())
            SecondWindowUI->setObjectName(QStringLiteral("SecondWindowUI"));
        SecondWindowUI->resize(325, 164);
        centralWidget = new QWidget(SecondWindowUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 283, 90));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        aButton = new QPushButton(layoutWidget);
        aButton->setObjectName(QStringLiteral("aButton"));
        QFont font;
        font.setPointSize(20);
        aButton->setFont(font);

        verticalLayout->addWidget(aButton);

        bButton = new QPushButton(layoutWidget);
        bButton->setObjectName(QStringLiteral("bButton"));
        bButton->setFont(font);

        verticalLayout->addWidget(bButton);

        SecondWindowUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SecondWindowUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 325, 21));
        SecondWindowUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SecondWindowUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SecondWindowUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SecondWindowUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SecondWindowUI->setStatusBar(statusBar);

        retranslateUi(SecondWindowUI);

        QMetaObject::connectSlotsByName(SecondWindowUI);
    } // setupUi

    void retranslateUi(QMainWindow *SecondWindowUI)
    {
        SecondWindowUI->setWindowTitle(QApplication::translate("SecondWindowUI", "SecondWindow", nullptr));
        aButton->setText(QApplication::translate("SecondWindowUI", "Mode A", nullptr));
        bButton->setText(QApplication::translate("SecondWindowUI", "Mode B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindowUI: public Ui_SecondWindowUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
