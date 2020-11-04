//
// Created by afentev on 10/21/20.
//

#ifndef TREES_MW_H
#define TREES_MW_H


/********************************************************************************
** Form generated from reading UI file 'formKM1107.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <QObject>
#include <QtWidgets/QGridLayout>
#include <QtGui>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QtWidgets/QGridLayout>

#include "../Trees/syncedtrees.h"

#include <iostream>

QT_BEGIN_NAMESPACE

class Ui_MainWindow;
class SecondWindow;
class CustomScene;

class SecondWindow: public QWidget {
Q_OBJECT

public:
    SecondWindow();
    ~SecondWindow() override;
    void link(bool, Ui_MainWindow*);
    QPushButton* pushButton;
    QLineEdit* lineEdit;
    QPushButton* pushButton1;

private:
    QGridLayout* gridLayout;
    QLabel* label;
};

class Ui_MainWindow: public QMainWindow {
Q_OBJECT

public:
    QWidget* centralwidget;
    QGraphicsView* vizualizator;
    CustomScene* scene;
    QFrame* horline;
    QComboBox* comboBox;
    QLabel* treetype_lbl;
    QSlider* scale_slider;
    QLabel* scaleminus_pic_lbl;
    QLabel* scaleplus_pic_lbl;
    QPushButton* addnrndbut;
    QPushButton* delnrndbut;
    QFrame* line1;
    QFrame* line2;
    QScrollArea* vertlist;
    QVBoxLayout* vertlistlayout;
    QWidget* scrollAreaWidgetContents;
    QFrame* line3;
    QLabel* addvtx_text_lbl;
    QLineEdit* addvtxfield;
    QPushButton* addvtxbut;
    QPushButton* remvtxbut;
    QLineEdit* remvtxfield;
    QLabel* remvtx_text_lbl;
    QFrame* line4;
    QFrame* line5;
    QLabel* stats_lbl;
    QLabel* nofv_lbl;
    QLabel* height_lbl;
    QLabel* blncon_lbl;
    QFrame* line6;
    QLabel* minel_lbl;
    QLabel* maxel_lbl;
    QLabel* medellbl;
    QLabel* nofvtx_val;
    QLabel* height_val;
    QLabel* balancedon_val;
    QLabel* minel_val;
    QLabel* macel_val;
    QLabel* medel_val;

    void setupUi(QMainWindow* MainWindow);
    void retranslateUi(QMainWindow* MainWindow) const;
    void draw_tree(Tree*, int x = -65, int y = 25);

    SyncedTrees* t;
    SecondWindow* x;
    long double prev = 1.0;
    QObject* ignore = nullptr;
    bool deleting = false;

private:
    int drawer(Tree*, int y = 0, bool first = true);
    int curl = -683 / 2;
    int curb = 679;
    int maxl;
    int maxr;
    int maxb;
    int maxu;
    int xcords = 0;
    int tot_vertexes = 0;

    void updateScrollArea(const QString&);
    void clearLayout(QLayout*);
    static std::string conv(long double);
    int32_t minimum = 1e9;
    int32_t maximum = -1e9;
    int32_t median = 0;
    std::vector<int> med_helper;

public slots:
    void addnrndbutHandler();
    void delnrndbutHandler();
    void addvtxbutHandler();
    void remvtxbutHandler();
    void rescaleHandler();
    void comboxHandler();
    void addHandler();
    void remallHandler();
    void remrndHandler();
};

class CustomItem: public QGraphicsEllipseItem {
public:
    int n;
    Ui_MainWindow* parent;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    int type() const override;

private:
    QPointF _center;
    bool _isResizing;
};

class CustomScene: public QGraphicsScene {
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    bool is_moving = false;
    std::pair<int, int> base;
    std::vector<std::pair<int, int>> cords;
};


class ThirdWindow: public QWidget {
Q_OBJECT

public:
    ThirdWindow();
    Ui_MainWindow* parent;

    void connect(int, Ui_MainWindow*);
    QPushButton* pushButton;
    QPushButton* pushButton_2;

private:
    QGridLayout* gridLayout;
    QLabel* label;
    QLineEdit* lineEdit;
    QLabel* label_2;
    QLineEdit* lineEdit_2;
    int n;

public slots:
    void remHandler();
    void updHandler();
};

class ClickableLabelUpd: public QLabel {
Q_OBJECT

public:
    explicit ClickableLabelUpd(QWidget *parent = nullptr) {
        setMouseTracking(true);
    }
    Ui_MainWindow* parent;
    QLineEdit* lbl;
    int elem;

protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void leaveEvent(QEvent*) override;
};

class ClickableLabelRem: public ClickableLabelUpd {
Q_OBJECT

protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void leaveEvent(QEvent*) override;
};

class ClickableLineEdit: public QLineEdit {
    Q_OBJECT

protected:
    void focusInEvent(QFocusEvent*) override;
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE


#endif //TREES_MW_H
