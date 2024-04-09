/********************************************************************************
** Form generated from reading UI file 'simple_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLE_PANEL_H
#define UI_SIMPLE_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskControlPanel
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_row_2;
    QPushButton *pushButton_3_2;
    QPushButton *pushButton_2_3;
    QPushButton *pushButton_2_4;
    QPushButton *pushButton_2_1;
    QPushButton *pushButton_2_2;
    QPushButton *pushButton_1_1;
    QPushButton *pushButton_1_2;
    QLabel *label_row_3;
    QLabel *label_row_1;
    QPushButton *pushButton_3_3;
    QPushButton *pushButton_3_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_status;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_regen;
    QPushButton *pushButton_clear;

    void setupUi(QWidget *TaskControlPanel)
    {
        if (TaskControlPanel->objectName().isEmpty())
            TaskControlPanel->setObjectName(QStringLiteral("TaskControlPanel"));
        TaskControlPanel->setWindowModality(Qt::NonModal);
        TaskControlPanel->resize(300, 200);
        TaskControlPanel->setMinimumSize(QSize(300, 200));
        TaskControlPanel->setMaximumSize(QSize(600, 400));
        gridLayoutWidget = new QWidget(TaskControlPanel);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 281, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_row_2 = new QLabel(gridLayoutWidget);
        label_row_2->setObjectName(QStringLiteral("label_row_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_row_2->sizePolicy().hasHeightForWidth());
        label_row_2->setSizePolicy(sizePolicy);
        label_row_2->setMinimumSize(QSize(100, 25));
        label_row_2->setMaximumSize(QSize(100, 25));
        label_row_2->setBaseSize(QSize(100, 25));
        QFont font;
        font.setFamily(QStringLiteral("Chilanka"));
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        label_row_2->setFont(font);
        label_row_2->setAlignment(Qt::AlignCenter);
        label_row_2->setWordWrap(false);

        gridLayout->addWidget(label_row_2, 1, 0, 1, 1);

        pushButton_3_2 = new QPushButton(gridLayoutWidget);
        pushButton_3_2->setObjectName(QStringLiteral("pushButton_3_2"));
        pushButton_3_2->setMinimumSize(QSize(25, 25));
        pushButton_3_2->setMaximumSize(QSize(50, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        pushButton_3_2->setFont(font1);
        pushButton_3_2->setMouseTracking(false);
        pushButton_3_2->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_3_2, 2, 2, 1, 1);

        pushButton_2_3 = new QPushButton(gridLayoutWidget);
        pushButton_2_3->setObjectName(QStringLiteral("pushButton_2_3"));
        pushButton_2_3->setMinimumSize(QSize(25, 25));
        pushButton_2_3->setMaximumSize(QSize(50, 25));
        pushButton_2_3->setFont(font1);
        pushButton_2_3->setMouseTracking(false);
        pushButton_2_3->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_2_3, 1, 3, 1, 1);

        pushButton_2_4 = new QPushButton(gridLayoutWidget);
        pushButton_2_4->setObjectName(QStringLiteral("pushButton_2_4"));
        pushButton_2_4->setMinimumSize(QSize(25, 25));
        pushButton_2_4->setMaximumSize(QSize(50, 25));
        pushButton_2_4->setFont(font1);
        pushButton_2_4->setMouseTracking(false);
        pushButton_2_4->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_2_4, 1, 4, 1, 1);

        pushButton_2_1 = new QPushButton(gridLayoutWidget);
        pushButton_2_1->setObjectName(QStringLiteral("pushButton_2_1"));
        pushButton_2_1->setMinimumSize(QSize(25, 25));
        pushButton_2_1->setMaximumSize(QSize(50, 25));
        pushButton_2_1->setFont(font1);
        pushButton_2_1->setMouseTracking(false);
        pushButton_2_1->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_2_1, 1, 1, 1, 1);

        pushButton_2_2 = new QPushButton(gridLayoutWidget);
        pushButton_2_2->setObjectName(QStringLiteral("pushButton_2_2"));
        pushButton_2_2->setMinimumSize(QSize(25, 25));
        pushButton_2_2->setMaximumSize(QSize(50, 25));
        pushButton_2_2->setFont(font1);
        pushButton_2_2->setMouseTracking(false);
        pushButton_2_2->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_2_2, 1, 2, 1, 1);

        pushButton_1_1 = new QPushButton(gridLayoutWidget);
        pushButton_1_1->setObjectName(QStringLiteral("pushButton_1_1"));
        pushButton_1_1->setMinimumSize(QSize(25, 25));
        pushButton_1_1->setMaximumSize(QSize(50, 25));
        pushButton_1_1->setFont(font1);
        pushButton_1_1->setMouseTracking(false);
        pushButton_1_1->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_1_1, 0, 1, 1, 1);

        pushButton_1_2 = new QPushButton(gridLayoutWidget);
        pushButton_1_2->setObjectName(QStringLiteral("pushButton_1_2"));
        pushButton_1_2->setMinimumSize(QSize(25, 25));
        pushButton_1_2->setMaximumSize(QSize(50, 25));
        pushButton_1_2->setFont(font1);
        pushButton_1_2->setMouseTracking(false);
        pushButton_1_2->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_1_2, 0, 2, 1, 1);

        label_row_3 = new QLabel(gridLayoutWidget);
        label_row_3->setObjectName(QStringLiteral("label_row_3"));
        sizePolicy.setHeightForWidth(label_row_3->sizePolicy().hasHeightForWidth());
        label_row_3->setSizePolicy(sizePolicy);
        label_row_3->setMinimumSize(QSize(100, 25));
        label_row_3->setMaximumSize(QSize(100, 25));
        label_row_3->setBaseSize(QSize(100, 25));
        label_row_3->setFont(font);
        label_row_3->setAlignment(Qt::AlignCenter);
        label_row_3->setWordWrap(false);

        gridLayout->addWidget(label_row_3, 2, 0, 1, 1);

        label_row_1 = new QLabel(gridLayoutWidget);
        label_row_1->setObjectName(QStringLiteral("label_row_1"));
        sizePolicy.setHeightForWidth(label_row_1->sizePolicy().hasHeightForWidth());
        label_row_1->setSizePolicy(sizePolicy);
        label_row_1->setMinimumSize(QSize(100, 25));
        label_row_1->setMaximumSize(QSize(100, 25));
        label_row_1->setBaseSize(QSize(100, 25));
        label_row_1->setFont(font);
        label_row_1->setAlignment(Qt::AlignCenter);
        label_row_1->setWordWrap(false);

        gridLayout->addWidget(label_row_1, 0, 0, 1, 1);

        pushButton_3_3 = new QPushButton(gridLayoutWidget);
        pushButton_3_3->setObjectName(QStringLiteral("pushButton_3_3"));
        pushButton_3_3->setMinimumSize(QSize(25, 25));
        pushButton_3_3->setMaximumSize(QSize(50, 25));
        pushButton_3_3->setFont(font1);
        pushButton_3_3->setMouseTracking(false);
        pushButton_3_3->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_3_3, 2, 3, 1, 1);

        pushButton_3_1 = new QPushButton(gridLayoutWidget);
        pushButton_3_1->setObjectName(QStringLiteral("pushButton_3_1"));
        pushButton_3_1->setMinimumSize(QSize(25, 25));
        pushButton_3_1->setMaximumSize(QSize(50, 25));
        pushButton_3_1->setFont(font1);
        pushButton_3_1->setMouseTracking(false);
        pushButton_3_1->setAutoFillBackground(true);

        gridLayout->addWidget(pushButton_3_1, 2, 1, 1, 1);

        verticalLayoutWidget = new QWidget(TaskControlPanel);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 281, 31));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_status = new QLabel(verticalLayoutWidget);
        label_status->setObjectName(QStringLiteral("label_status"));
        sizePolicy.setHeightForWidth(label_status->sizePolicy().hasHeightForWidth());
        label_status->setSizePolicy(sizePolicy);
        label_status->setMinimumSize(QSize(135, 25));
        label_status->setMaximumSize(QSize(270, 50));
        label_status->setBaseSize(QSize(100, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        label_status->setFont(font2);
        label_status->setAutoFillBackground(false);
        label_status->setAlignment(Qt::AlignCenter);
        label_status->setWordWrap(false);

        verticalLayout->addWidget(label_status);

        horizontalLayoutWidget = new QWidget(TaskControlPanel);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 150, 281, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_regen = new QPushButton(horizontalLayoutWidget);
        pushButton_regen->setObjectName(QStringLiteral("pushButton_regen"));
        pushButton_regen->setMinimumSize(QSize(25, 25));
        pushButton_regen->setMaximumSize(QSize(150, 25));
        QFont font3;
        font3.setFamily(QStringLiteral("Ubuntu"));
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        font3.setStrikeOut(false);
        pushButton_regen->setFont(font3);
        pushButton_regen->setMouseTracking(false);
        pushButton_regen->setAutoFillBackground(true);

        horizontalLayout->addWidget(pushButton_regen);

        pushButton_clear = new QPushButton(horizontalLayoutWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setMinimumSize(QSize(25, 25));
        pushButton_clear->setMaximumSize(QSize(150, 25));
        pushButton_clear->setFont(font1);
        pushButton_clear->setMouseTracking(false);
        pushButton_clear->setAutoFillBackground(true);

        horizontalLayout->addWidget(pushButton_clear);


        retranslateUi(TaskControlPanel);

        QMetaObject::connectSlotsByName(TaskControlPanel);
    } // setupUi

    void retranslateUi(QWidget *TaskControlPanel)
    {
        TaskControlPanel->setWindowTitle(QApplication::translate("TaskControlPanel", "Form", Q_NULLPTR));
        label_row_2->setText(QApplication::translate("TaskControlPanel", "Box", Q_NULLPTR));
        pushButton_3_2->setText(QApplication::translate("TaskControlPanel", "2", Q_NULLPTR));
        pushButton_2_3->setText(QApplication::translate("TaskControlPanel", "3", Q_NULLPTR));
        pushButton_2_4->setText(QApplication::translate("TaskControlPanel", "4", Q_NULLPTR));
        pushButton_2_1->setText(QApplication::translate("TaskControlPanel", "1", Q_NULLPTR));
        pushButton_2_2->setText(QApplication::translate("TaskControlPanel", "2", Q_NULLPTR));
        pushButton_1_1->setText(QApplication::translate("TaskControlPanel", "1", Q_NULLPTR));
        pushButton_1_2->setText(QApplication::translate("TaskControlPanel", "2", Q_NULLPTR));
        label_row_3->setText(QApplication::translate("TaskControlPanel", "Vehicle", Q_NULLPTR));
        label_row_1->setText(QApplication::translate("TaskControlPanel", "Assembly Line", Q_NULLPTR));
        pushButton_3_3->setText(QApplication::translate("TaskControlPanel", "3", Q_NULLPTR));
        pushButton_3_1->setText(QApplication::translate("TaskControlPanel", "1", Q_NULLPTR));
        label_status->setText(QApplication::translate("TaskControlPanel", "Please select a goal pose", Q_NULLPTR));
        pushButton_regen->setText(QApplication::translate("TaskControlPanel", "Respawn Objects", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("TaskControlPanel", "Clear Objects", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TaskControlPanel: public Ui_TaskControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLE_PANEL_H
