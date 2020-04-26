/********************************************************************************
** Form generated from reading UI file 'jiezhongform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JIEZHONGFORM_H
#define UI_JIEZHONGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JieZhongForm
{
public:
    QLabel *label_4;
    QLabel *weight;
    QPushButton *searchButton;
    QLabel *label_5;
    QLabel *atype;
    QPushButton *submitButton;
    QLabel *label_9;
    QTextEdit *uidEdit;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QPushButton *getUidButton;
    QLabel *age;
    QLabel *label_7;

    void setupUi(QWidget *JieZhongForm)
    {
        if (JieZhongForm->objectName().isEmpty())
            JieZhongForm->setObjectName(QStringLiteral("JieZhongForm"));
        JieZhongForm->resize(1000, 800);
        label_4 = new QLabel(JieZhongForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 280, 131, 21));
        QFont font;
        font.setPointSize(12);
        label_4->setFont(font);
        weight = new QLabel(JieZhongForm);
        weight->setObjectName(QStringLiteral("weight"));
        weight->setGeometry(QRect(260, 310, 111, 41));
        weight->setFont(font);
        searchButton = new QPushButton(JieZhongForm);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(200, 160, 91, 41));
        searchButton->setFont(font);
        label_5 = new QLabel(JieZhongForm);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 330, 141, 21));
        label_5->setFont(font);
        atype = new QLabel(JieZhongForm);
        atype->setObjectName(QStringLiteral("atype"));
        atype->setGeometry(QRect(260, 240, 51, 16));
        submitButton = new QPushButton(JieZhongForm);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(650, 430, 101, 41));
        submitButton->setFont(font);
        label_9 = new QLabel(JieZhongForm);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 240, 51, 16));
        uidEdit = new QTextEdit(JieZhongForm);
        uidEdit->setObjectName(QStringLiteral("uidEdit"));
        uidEdit->setGeometry(QRect(90, 110, 281, 31));
        groupBox = new QGroupBox(JieZhongForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(420, 110, 341, 311));
        groupBox->setFont(font);
        label_3 = new QLabel(JieZhongForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 230, 151, 31));
        label_3->setFont(font);
        label_6 = new QLabel(JieZhongForm);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 225, 111, 31));
        label_6->setFont(font);
        label = new QLabel(JieZhongForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 110, 81, 31));
        label->setFont(font);
        label_2 = new QLabel(JieZhongForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 430, 291, 41));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        getUidButton = new QPushButton(JieZhongForm);
        getUidButton->setObjectName(QStringLiteral("getUidButton"));
        getUidButton->setGeometry(QRect(90, 160, 75, 41));
        getUidButton->setFont(font);
        age = new QLabel(JieZhongForm);
        age->setObjectName(QStringLiteral("age"));
        age->setGeometry(QRect(260, 270, 121, 31));
        age->setFont(font);
        label_7 = new QLabel(JieZhongForm);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 0, 1000, 800));
        label_7->setStyleSheet(QString::fromUtf8("background-image: url(:/image/\346\263\250\345\260\204\347\226\253\350\213\227.jpg);"));
        label_7->raise();
        label_4->raise();
        weight->raise();
        searchButton->raise();
        label_5->raise();
        atype->raise();
        submitButton->raise();
        label_9->raise();
        uidEdit->raise();
        groupBox->raise();
        label_3->raise();
        label_6->raise();
        label->raise();
        label_2->raise();
        getUidButton->raise();
        age->raise();

        retranslateUi(JieZhongForm);

        QMetaObject::connectSlotsByName(JieZhongForm);
    } // setupUi

    void retranslateUi(QWidget *JieZhongForm)
    {
        JieZhongForm->setWindowTitle(QApplication::translate("JieZhongForm", "Form", 0));
        label_4->setText(QApplication::translate("JieZhongForm", "\346\227\245\351\276\204\357\274\210\345\244\251\357\274\211\357\274\232", 0));
        weight->setText(QString());
        searchButton->setText(QApplication::translate("JieZhongForm", "\346\237\245\350\257\242", 0));
        label_5->setText(QApplication::translate("JieZhongForm", "\344\275\223\351\207\215\357\274\210\345\205\254\346\226\244\357\274\211\357\274\232", 0));
        atype->setText(QString());
        submitButton->setText(QApplication::translate("JieZhongForm", "\346\217\220\344\272\244", 0));
        label_9->setText(QString());
        groupBox->setTitle(QApplication::translate("JieZhongForm", "\351\234\200\350\246\201\346\263\250\345\260\204\347\232\204\347\226\253\350\213\227", 0));
        label_3->setText(QApplication::translate("JieZhongForm", "\347\247\215\347\261\273\357\274\232", 0));
        label_6->setText(QString());
        label->setText(QApplication::translate("JieZhongForm", "\345\215\241\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("JieZhongForm", "\345\260\206\346\263\250\345\260\204\345\220\216\347\232\204\347\226\253\350\213\227\346\211\223\351\222\251\345\220\216\347\202\271\345\207\273", 0));
        getUidButton->setText(QApplication::translate("JieZhongForm", "\345\257\273\345\215\241", 0));
        age->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JieZhongForm: public Ui_JieZhongForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JIEZHONGFORM_H
