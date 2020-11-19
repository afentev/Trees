//
// Created by afentev on 10/21/20.
//

#include "mw.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <unordered_set>
#include <queue>
#include <random>
#include <QtWidgets/QGraphicsProxyWidget>

void Ui_MainWindow::setupUi(QMainWindow* MainWindow) {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromStdString("MainWindow"));
    MainWindow->resize(1019, 701);
    MainWindow->setMinimumSize(QSize(1019, 701));
    MainWindow->setMaximumSize(QSize(1019, 701));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromStdString("centralwidget"));

    scene = new CustomScene;
    vizualizator = new QGraphicsView(centralwidget);
    vizualizator->setObjectName(QString::fromStdString("visualizator"));
    vizualizator->setGeometry(QRect(10, 10, 701, 681));
    vizualizator->setScene(scene);
    scene->setSceneRect(-683/2, 0, 683, 679);

    horline = new QFrame(centralwidget);
    horline->setObjectName(QString::fromStdString("horline"));
    horline->setGeometry(QRect(717, 10, 16, 681));
    horline->setFrameShape(QFrame::VLine);
    horline->setFrameShadow(QFrame::Sunken);
    comboBox = new QComboBox(centralwidget);
    comboBox->setObjectName(QString::fromStdString("comboBox"));
    comboBox->setGeometry(QRect(740, 30, 261, 26));
    treetype_lbl = new QLabel(centralwidget);
    treetype_lbl->setObjectName(QString::fromStdString("treetype_lbl"));
    treetype_lbl->setGeometry(QRect(740, 10, 241, 20));
    treetype_lbl->setAlignment(Qt::AlignCenter);
    scale_slider = new QSlider(centralwidget);
    scale_slider->setObjectName(QString::fromStdString("scale_slider"));
    scale_slider->setGeometry(QRect(770, 673, 190, 16));
    scale_slider->setMaximum(100);
    scale_slider->setValue(50);
    scale_slider->setOrientation(Qt::Horizontal);
    scaleminus_pic_lbl = new QLabel(centralwidget);
    scaleminus_pic_lbl->setObjectName(QString::fromStdString("scaleminus_pic_lbl"));
    scaleminus_pic_lbl->setGeometry(QRect(740, 665, 31, 31));
    scaleplus_pic_lbl = new QLabel(centralwidget);
    scaleplus_pic_lbl->setObjectName(QString::fromStdString("scaleplus_pic_lbl"));
    scaleplus_pic_lbl->setGeometry(QRect(970, 665, 31, 31));
    addnrndbut = new QPushButton(centralwidget);
    addnrndbut->setObjectName(QString::fromStdString("addnrndbut"));
    addnrndbut->setGeometry(QRect(736, 70, 268, 32));
    delnrndbut = new QPushButton(centralwidget);
    delnrndbut->setObjectName(QString::fromStdString("delnrndbut"));
    delnrndbut->setGeometry(QRect(736, 100, 268, 32));
    line1 = new QFrame(centralwidget);
    line1->setObjectName(QString::fromStdString("line1"));
    line1->setGeometry(QRect(742, 56, 256, 20));
    line1->setFrameShape(QFrame::HLine);
    line1->setFrameShadow(QFrame::Sunken);
    line2 = new QFrame(centralwidget);
    line2->setObjectName(QString::fromStdString("line2"));
    line2->setGeometry(QRect(742, 126, 256, 20));
    line2->setFrameShape(QFrame::HLine);
    line2->setFrameShadow(QFrame::Sunken);
    vertlist = new QScrollArea(centralwidget);
    vertlist->setObjectName(QString::fromStdString("vertlist"));
    vertlist->setGeometry(QRect(742, 148, 256, 231));
    vertlist->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(
            QString::fromStdString("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 254, 229));
    vertlist->setWidget(scrollAreaWidgetContents);
    line3 = new QFrame(centralwidget);
    line3->setObjectName(QString::fromStdString("line3"));
    line3->setGeometry(QRect(742, 383, 256, 20));
    line3->setFrameShape(QFrame::HLine);
    line3->setFrameShadow(QFrame::Sunken);
    addvtx_text_lbl = new QLabel(centralwidget);
    addvtx_text_lbl->setObjectName(QString::fromStdString("addvtx_text_lbl"));
    addvtx_text_lbl->setGeometry(QRect(740, 401, 241, 20));
    addvtx_text_lbl->setAlignment(Qt::AlignCenter);
    addvtxfield = new QLineEdit(centralwidget);
    addvtxfield->setObjectName(QString::fromStdString("addvtxfield"));
    addvtxfield->setGeometry(QRect(742, 430, 113, 21));
    addvtxbut = new QPushButton(centralwidget);
    addvtxbut->setObjectName(QString::fromStdString("addvtxbut"));
    addvtxbut->setGeometry(QRect(871, 426, 131, 32));
    remvtxbut = new QPushButton(centralwidget);
    remvtxbut->setObjectName(QString::fromStdString("remvtxbut"));
    remvtxbut->setGeometry(QRect(871, 503, 131, 32));
    remvtxfield = new QLineEdit(centralwidget);
    remvtxfield->setObjectName(QString::fromStdString("remvtxfield"));
    remvtxfield->setGeometry(QRect(742, 507, 113, 21));
    remvtx_text_lbl = new QLabel(centralwidget);
    remvtx_text_lbl->setObjectName(QString::fromStdString("remvtx_text_lbl"));
    remvtx_text_lbl->setGeometry(QRect(740, 478, 241, 20));
    remvtx_text_lbl->setAlignment(Qt::AlignCenter);
    line4 = new QFrame(centralwidget);
    line4->setObjectName(QString::fromStdString("line4"));
    line4->setGeometry(QRect(742, 458, 256, 20));
    line4->setFrameShape(QFrame::HLine);
    line4->setFrameShadow(QFrame::Sunken);
    line5 = new QFrame(centralwidget);
    line5->setObjectName(QString::fromStdString("line5"));
    line5->setGeometry(QRect(742, 531, 256, 20));
    line5->setFrameShape(QFrame::HLine);
    line5->setFrameShadow(QFrame::Sunken);
    stats_lbl = new QLabel(centralwidget);
    stats_lbl->setObjectName(QString::fromStdString("stats_lbl"));
    stats_lbl->setGeometry(QRect(740, 550, 241, 20));
    stats_lbl->setAlignment(Qt::AlignCenter);
    nofv_lbl = new QLabel(centralwidget);
    nofv_lbl->setObjectName(QString::fromStdString("nofv_lbl"));
    nofv_lbl->setGeometry(QRect(743, 580, 91, 16));
    height_lbl = new QLabel(centralwidget);
    height_lbl->setObjectName(QString::fromStdString("height_lbl"));
    height_lbl->setGeometry(QRect(743, 605, 51, 16));
    blncon_lbl = new QLabel(centralwidget);
    blncon_lbl->setObjectName(QString::fromStdString("blncon_lbl"));
    blncon_lbl->setGeometry(QRect(743, 630, 81, 16));
    line6 = new QFrame(centralwidget);
    line6->setObjectName(QString::fromStdString("line6"));
    line6->setGeometry(QRect(740, 650, 256, 20));
    line6->setFrameShape(QFrame::HLine);
    line6->setFrameShadow(QFrame::Sunken);
    minel_lbl = new QLabel(centralwidget);
    minel_lbl->setObjectName(QString::fromStdString("minel_lbl"));
    minel_lbl->setGeometry(QRect(880, 580, 58, 16));
    maxel_lbl = new QLabel(centralwidget);
    maxel_lbl->setObjectName(QString::fromStdString("maxel_lbl"));
    maxel_lbl->setGeometry(QRect(880, 605, 58, 16));
    medellbl = new QLabel(centralwidget);
    medellbl->setObjectName(QString::fromStdString("medellbl"));
    medellbl->setGeometry(QRect(880, 630, 58, 16));
    nofvtx_val = new QLabel(centralwidget);
    nofvtx_val->setObjectName(QString::fromStdString("nofvtx_val"));
    nofvtx_val->setGeometry(QRect(840, 580, 41, 16));
    QFont font;
    font.setPointSize(11);
    font.setBold(true);
    font.setWeight(75);
    nofvtx_val->setFont(font);
    height_val = new QLabel(centralwidget);
    height_val->setObjectName(QString::fromStdString("height_val"));
    height_val->setGeometry(QRect(840, 605, 41, 16));
    height_val->setFont(font);
    balancedon_val = new QLabel(centralwidget);
    balancedon_val->setObjectName(QString::fromStdString("balancedon_val"));
    balancedon_val->setGeometry(QRect(840, 630, 41, 16));
    QFont font1;
    font1.setPointSize(11);
    font1.setBold(true);
    font1.setUnderline(false);
    font1.setWeight(75);
    balancedon_val->setFont(font1);
    minel_val = new QLabel(centralwidget);
    minel_val->setObjectName(QString::fromStdString("minel_val"));
    minel_val->setGeometry(QRect(940, 580, 71, 16));
    minel_val->setFont(font);
    macel_val = new QLabel(centralwidget);
    macel_val->setObjectName(QString::fromStdString("macel_val"));
    macel_val->setGeometry(QRect(940, 605, 71, 16));
    macel_val->setFont(font);
    medel_val = new QLabel(centralwidget);
    medel_val->setObjectName(QString::fromStdString("medel_val"));
    medel_val->setGeometry(QRect(940, 630, 71, 16));
    medel_val->setFont(font);
    MainWindow->setCentralWidget(centralwidget);

    retranslateUi(MainWindow);

    QObject::connect(addvtxbut, SIGNAL (released()), this, SLOT (addvtxbutHandler()));
    QObject::connect(addnrndbut, SIGNAL (released()), this, SLOT (addnrndbutHandler()));
    QObject::connect(delnrndbut, SIGNAL (released()), this, SLOT (delnrndbutHandler()));
    QObject::connect(remvtxbut, SIGNAL (released()), this, SLOT (remvtxbutHandler()));
    QObject::connect(scale_slider, SIGNAL(valueChanged(int)),
                     this, SLOT(rescaleHandler()));
    QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), this,
                     SLOT(comboxHandler()));

    auto* val = new QRegExpValidator(QRegExp("0|-?[123456789]\\d{1,8}"));
    addvtxfield->setValidator(val);
    remvtxfield->setValidator(val);

    scaleplus_pic_lbl->setPixmap(QPixmap(QString::fromUtf8(
            "/Users/user/Downloads/plus-2.png")).scaled(15, 15,
                                                        Qt::KeepAspectRatio,
                                                        Qt::SmoothTransformation));
    scaleminus_pic_lbl->setPixmap(QPixmap(QString::fromUtf8(
            "/Users/user/Downloads/minus-2.png")).scaled(15, 15,
                                                         Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation));

    comboBox->setCurrentIndex(1);
    vertlistlayout = new QVBoxLayout;
    scrollAreaWidgetContents->setLayout(vertlistlayout);

    QMetaObject::connectSlotsByName(MainWindow);
}

void Ui_MainWindow::retranslateUi(QMainWindow* MainWindow) const {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow",
                                                       "Trees vizualizator", Q_NULLPTR));
    comboBox->clear();
    comboBox->insertItems(0, QStringList()
            << QApplication::translate("MainWindow", "Binary search tree", Q_NULLPTR)
            << QApplication::translate("MainWindow", "AVL tree", Q_NULLPTR)
            << QApplication::translate("MainWindow", "Red-black tree", Q_NULLPTR)
            << QApplication::translate("MainWindow", "2-3 tree", Q_NULLPTR)
            << QApplication::translate("MainWindow",
                                       "Random binary search tree", Q_NULLPTR)
            << QApplication::translate("MainWindow", "Min-heap", Q_NULLPTR)
    );
    treetype_lbl->setText(QApplication::translate("MainWindow", "Tree Type:", Q_NULLPTR));
    scaleminus_pic_lbl->setText(QApplication::translate("MainWindow", "PIC", Q_NULLPTR));
    scaleplus_pic_lbl->setText(QApplication::translate("MainWindow", "PIC", Q_NULLPTR));
    addnrndbut->setText(QApplication::translate("MainWindow",
                                                "Add N random vertexes", Q_NULLPTR));
    delnrndbut->setText(QApplication::translate("MainWindow",
                                                "Remove N random vertexes", Q_NULLPTR));
    addvtx_text_lbl->setText(QApplication::translate("MainWindow",
                                                     "Add vertex", Q_NULLPTR));
    addvtxbut->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
    remvtxbut->setText(QApplication::translate("MainWindow", "Remove", Q_NULLPTR));
    remvtx_text_lbl->setText(QApplication::translate("MainWindow", "Remove vertex",
                                                     Q_NULLPTR));
    stats_lbl->setText(QApplication::translate("MainWindow", "Tree stats", Q_NULLPTR));
    nofv_lbl->setText(QApplication::translate("MainWindow",
                                              "N. of vertexes:", Q_NULLPTR));
    height_lbl->setText(QApplication::translate("MainWindow", "Height:", Q_NULLPTR));
    blncon_lbl->setText(QApplication::translate("MainWindow", "Balanced on:", Q_NULLPTR));
    minel_lbl->setText(QApplication::translate("MainWindow", "Min el-t:", Q_NULLPTR));
    maxel_lbl->setText(QApplication::translate("MainWindow", "Max el-t:", Q_NULLPTR));
    medellbl->setText(QApplication::translate("MainWindow", "Med el-t:", Q_NULLPTR));
    nofvtx_val->setText(QApplication::translate("MainWindow", "10000", Q_NULLPTR));
    height_val->setText(QApplication::translate("MainWindow", "10000", Q_NULLPTR));
    balancedon_val->setText(QApplication::translate("MainWindow", "10000", Q_NULLPTR));
    minel_val->setText(QApplication::translate("MainWindow", "10000", Q_NULLPTR));
    macel_val->setText(QApplication::translate("MainWindow", "10000", Q_NULLPTR));
    medel_val->setText(QApplication::translate("MainWindow", "10000", Q_NULLPTR));
}

void Ui_MainWindow::addnrndbutHandler() {
    x = new SecondWindow;
    x->link(true, this);
    QObject::connect(x->pushButton, SIGNAL(released()), this, SLOT(addHandler()));
    x->show();
}

void Ui_MainWindow::addHandler() {
    auto text = x->lineEdit->text().toStdString();
    if (text.empty() || text == "-") {
        return;
    }
    int number = std::stoi(text);
    for (int i = 0; i < number; ++i) {
        int elem = rand() % 1000000000;
        if ((rand() % 2) == 0) {
            elem *= -1;
        }
        t->insert(elem, reinterpret_cast<Tree *&>(t));
        birds[elem] = (rand() % 10) < 5;

    }
    draw_tree(t, -65, 25);
    x->deleteLater();
    delete x;
    x = nullptr;
}

void Ui_MainWindow::delnrndbutHandler() {
    x = new SecondWindow;
    x->link(false, this);
    QObject::connect(x->pushButton, SIGNAL (released()),
                     this, SLOT (addvtxbutHandler()));
    QObject::connect(x->pushButton1, SIGNAL (released()), this, SLOT (remallHandler()));
    x->show();
}

void Ui_MainWindow::addvtxbutHandler() {
    auto text = addvtxfield->text().toStdString();
    if (text.empty() || text == "-") {
        return;
    }
    int n = std::stoi(text);
    t->insert(n, reinterpret_cast<Tree *&>(t));
    birds[n] = (rand() % 10) < 5;
    draw_tree(t, -65, 25);
    addvtxfield->setText("");
}

void Ui_MainWindow::remvtxbutHandler() {
    auto text = remvtxfield->text().toStdString();
    if (text.empty() || text == "-") {
        return;
    }
    int n = std::stoi(text);
    t->remove(n, reinterpret_cast<Tree *&>(t));
    birds.erase(birds.find(n));
    draw_tree(t, -65, 25);
    remvtxfield->setText("");
}


void Ui_MainWindow::draw_tree(Tree* tt, int x, int y) {
    for (auto o: scene->items()) {
        delete o;
    }
    scene->clear();

    maxl = 0;
    maxr = 0;
    maxb = 0;
    maxu = 0;

    xcords = 0;
    // clear scrollarea
    tot_vertexes = 0;
    clearLayout(vertlistlayout);

    minimum = INT32_MAX;
    maximum = INT32_MIN;

    drawer(tt, y);

    std::sort(med_helper.begin(), med_helper.end());
    median = med_helper[med_helper.size() / 2];
    med_helper.clear();

    int dxl = -683 / 2 - maxl;
    int dxr = 683 / 2 - maxr;
    int ddx = dxl + dxr;
    maxl += ddx / 2;
    maxr += ddx / 2;

    long double r = std::max(static_cast<long double>(std::abs(maxl)) / std::abs(curl), std::max(
            static_cast<long double>(std::abs(maxr)) / std::abs(maxr),
            static_cast<long double>(std::abs(maxb)) / std::abs(curb)));

    double ddb = static_cast<double>(std::abs(maxb)) / 679.0;
    int dy1 = std::max(0, maxb - 679);
    auto i = vizualizator->sceneRect();

    for (auto o: scene->items()) {
        auto p = o->pos();
        o->setPos(p.x() + ddx / 2, p.y() - dy1 / 2 - 15); // -15 еще для красоты
    }

    if (r > 1.0) {
        scale_slider->setValue(std::max(1.0l, 50.0 / r));
    } else {
        scale_slider->setValue(std::min(100.0l, 50.0 / r));
    }

    nofvtx_val->setText(QString::fromStdString(std::to_string(tot_vertexes)));
    height_val->setText(QString::fromStdString(std::to_string(t->height())));
    long double k = std::log2(tot_vertexes + 1) - 1;
    long double arg1 = ((2 * (k - 1) * std::pow(2, k) + 2) / tot_vertexes) / k;
    long double arg2 = t->measure(tot_vertexes, t);
    balancedon_val->setText(QString::fromStdString(conv(arg2 / arg1)));
    minel_val->setText(QString::fromStdString(std::to_string(minimum)));
    macel_val->setText(QString::fromStdString(std::to_string(maximum)));
    medel_val->setText(QString::fromStdString(std::to_string(median)));

    ignore = nullptr;
    deleting = false;
    if (t->bst_tree == nullptr) {
        delete t;
        t = nullptr;
        t = new SyncedTrees;
        t->init();
        draw_tree(t);
    }
}

void Ui_MainWindow::rescaleHandler() {
    if (scale_slider->value() == 0) {
        return;
    }
    long double ratio = scale_slider->value() / 50.0;
    vizualizator->scale(1 / prev, 1 / prev);
    vizualizator->scale(ratio, ratio);
    prev = ratio;
}

int Ui_MainWindow::drawer(Tree* tt, int y, bool first) {
    bool rbt = t->name == 3;

    if (tt == nullptr) {
        return xcords;
    } else if (first) {
        if (dynamic_cast<SyncedTrees*>(tt)->bst_tree == nullptr) {
            return xcords;
        }
    }
    if (t->name == 3) {
        if (first) {
            if (!dynamic_cast<SyncedTrees*>(tt)->rbt_tree->is_valid()) {
                return xcords;
            }
        } else if (!reinterpret_cast<RBTree*>(tt)->is_valid()) {
            return xcords;
        }
    }
    int mem = -1;
    int dy;
    if (tt->getLeft() != nullptr) {
        if (tt->getLeft()->getElem() != 1.1e9) {
            dy = y + 200;
            mem = drawer(tt->getLeft(), dy, false);
        }
    }

    auto* item = new CustomItem;
    item->setRect(10, 10, 100, 48);
    item->setFlags(QGraphicsItem::ItemIsSelectable);
    int n = tt->getElem();
    item->n = n;
    item->parent = this;
    if (rbt) {
        RBTree* w;
        if (first) {
            w = reinterpret_cast<SyncedTrees*>(tt)->rbt_tree;
        } else {
            w = reinterpret_cast<RBTree*>(tt);
        }
        if (w->getRoot()->color) {
            item->setBrush(QBrush(QColor::fromRgb(255, 0, 0, 180)));
            item->setPen(QPen(QColor::fromRgb(255, 0, 0, 180)));
        }
    }
    auto string = std::to_string(tt->getElem());
    std::cout << string << std::endl;
    auto t_ = QString::fromStdString(string);
    qDebug() << t_;
    updateScrollArea(t_);
    item->setPos(xcords * 90, y);
    scene->addItem(item);
    auto text = scene->addText(t_);
    text->setTextWidth(100);
    text->setPos(xcords * 90 + 50 - (tt->getElem() == 0? 1: std::log10(
            std::fabs(tt->getElem()))) * 3.5, y + 24);

    maxl = std::min(maxl, xcords * 90);
    maxr = std::max(maxr, xcords * 90 + 100);
    maxb = std::max(maxb, y + 48);
    maxu = std::min(maxu, y);

    minimum = std::min(minimum, n);
    maximum = std::max(maximum, n);
    med_helper.push_back(n);

    int ret1 = xcords;
    xcords++;

    if (mem != -1 && tt->getLeft() != nullptr) {
        if (rbt) {
            auto* w = reinterpret_cast<RBTree*>(tt);
            if (w->getLeft() != nullptr) {
                if (dynamic_cast<RBTree*>(w->getLeft())->is_valid()) {
                    scene->addLine(ret1 * 90 + 57, y + 58,
                                   mem * 90 + 57, dy + 10);
                }
            }
        } else {
            scene->addLine(ret1 * 90 + 57, y + 58,
                           mem * 90 + 57, dy + 10);

            if (birds[tt->getLeft()->getElem()]) {
                QPixmap pixmap("/Users/user/Documents/RoseBird.png");
                pixmap = pixmap.scaled(70, 70, Qt::KeepAspectRatio,
                                       Qt::SmoothTransformation);

                auto* lbl = scene->addPixmap(pixmap);
                lbl->setPos((ret1 * 90 + 57 + mem * 90 + 57) / 2 - 50, (y + 58 + dy + 10) / 2 - 50);
            }
        }
    }

    if (tt->getRight() != nullptr) {
        if (tt->getRight()->getElem() != 1.1e9) {
            if (rbt) {
                RBTree* w = reinterpret_cast<RBTree *>(tt);
                if (w->getRight() != nullptr) {
                    if (dynamic_cast<RBTree*>(w->getRight())->is_valid()) {
                        dy = y + 200;
                        mem = drawer(tt->getRight(), dy, false);
                        if (mem != -1) {
                            scene->addLine(ret1 * 90 + 57, y + 58,
                                           mem * 90 + 64, dy + 10);
                        }
                    }
                }
            } else {
                dy = y + 200;
                mem = drawer(tt->getRight(), dy, false);
                if (mem != -1) {
                    scene->addLine(ret1 * 90 + 57, y + 58,
                                   mem * 90 + 64, dy + 10);

                    if (birds[tt->getRight()->getElem()]) {
                        auto lbl = scene->addPixmap(QPixmap("/Users/user/Documents/"
                                                            "BlueBird.png").scaled(
                                50, 50,
                                Qt::KeepAspectRatio,
                                Qt::SmoothTransformation));
                        lbl->setPos((ret1 * 90 + 57 + mem * 90 + 57) / 2, (y + 58 + dy + 10) / 2 - 30);
                    }
                }
            }
        }
    }

    return ret1;
}

void Ui_MainWindow::comboxHandler() {
    std::string nnew = comboBox->currentText().toStdString();
    if (t != nullptr) {
        if (nnew == "AVL tree") {
            t->name = 1;
        } else if (nnew == "Binary search tree") {
            t->name = 0;
        } else if (nnew == "Random binary search tree") {
            t->name = 2;
        } else if (nnew == "Red-black tree") {
            t->name = 3;
        }
        draw_tree(t);
    }
}

void Ui_MainWindow::updateScrollArea(const QString& y) {
    auto* wdg = new QWidget;
    auto* layout = new QHBoxLayout;
    auto* le = new ClickableLineEdit;
    auto* upd = new ClickableLabelUpd;
    auto* del = new ClickableLabelRem;
    auto* nn = new QLabel;
    wdg->setLayout(layout);

    le->setText(y);
    auto* val = new QRegExpValidator(QRegExp("0|-?[123456789]\\d{1,8}"));
    le->setValidator(val);
    nn->setText(QString::fromStdString(std::to_string(++tot_vertexes) + '.'));
    layout->addWidget(nn, 1);
    layout->addWidget(le, 5);
    layout->addWidget(upd, 1);
    layout->addWidget(del, 1);

    QImage image("/Users/user/Downloads/Webp.net-resizeimage-3.png");
    QPainter p;
    p.begin(&image);
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.fillRect(image.rect(), QColor(0, 0, 0, 50));
    p.end();
    upd->setPixmap(QPixmap::fromImage(image));
    upd->parent = this;
    upd->lbl = le;
    upd->elem = std::stoi(y.toStdString());

    QImage image1("/Users/user/Downloads/Webp.net-resizeimage-4.png");
    QPainter p1;
    p1.begin(&image1);
    p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p1.fillRect(image1.rect(), QColor(0, 0, 0, 50));
    p1.end();
    del->setPixmap(QPixmap::fromImage(image1));
    del->parent = this;
    del->lbl = le;
    del->elem = std::stoi(y.toStdString());

    vertlistlayout->addWidget(wdg);

    auto* l = new QFrame;
    l->setFrameShape(QFrame::HLine);
    l->setFrameShadow(QFrame::Sunken);
    vertlistlayout->addWidget(l);
}

SecondWindow::SecondWindow() {
    this->resize(260, 88);
    gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QString::fromStdString("gridLayout"));
    label = new QLabel(this);
    label->setObjectName(QString::fromStdString("label"));
    label->setText("n = ");

    gridLayout->addWidget(label, 0, 0, 1, 1);

    lineEdit = new QLineEdit(this);
    lineEdit->setObjectName(QString::fromStdString("lineEdit"));
    auto* val = new QRegExpValidator(QRegExp("[123456789]\\d+"));
    lineEdit->setValidator(val);

    gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

    pushButton = new QPushButton(this);
    pushButton->setObjectName(QString::fromStdString("pushButton"));

    gridLayout->addWidget(pushButton, 1, 0, 1, 2);

    QMetaObject::connectSlotsByName(this);
}

SecondWindow::~SecondWindow() {
    delete label;
    delete lineEdit;
    delete pushButton;
    delete gridLayout;
    deleteLater();
}

void SecondWindow::link(bool add, Ui_MainWindow* parent) {
    if (add) {
        pushButton->setText("Add");
        this->setWindowTitle("Add random vertexes");
        QObject::connect(pushButton, SIGNAL (released()), parent, SLOT (addvtxbutHandler()));
    } else {
        pushButton->setText("Remove");
        this->setWindowTitle("Remove random vertexes");
        QObject::connect(pushButton, SIGNAL(released()), parent, SLOT(remrndHandler()));

        pushButton1 = new QPushButton;
        pushButton1->setText("Remove all");
        gridLayout->addWidget(pushButton1, 2, 0, 1, 2);
    }
}

void Ui_MainWindow::clearLayout(QLayout* layout) {
    QLayoutItem* item;
    int skipped = 0;
    while((item = layout->takeAt(0))) {
        if (item->widget()->layout()) {
            clearLayout(item->widget()->layout());
            delete item->widget()->layout();
        }
        if (item->widget()) {
            if (!deleting) {
                delete item->widget();
            } else {
                if (item->widget() != ignore) {
                    delete item->widget();
                } else {
                    skipped++;
                    qDebug() << "SKIPPED";
                }
            }
        }
        if (!deleting) {
            delete item;
        } else {
            if (item->widget() != ignore) {
                delete item;
            } else {
                skipped++;
                qDebug() << "SKIPPED1";
            }
        }
    }
}

std::string Ui_MainWindow::conv(long double arg) {
    long double number = std::round(100 * std::powl(2.718281828459045l,
                                                    -std::fabs(arg - 1))) / 100;
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << number;
    return ss.str();
}

void Ui_MainWindow::remallHandler() {
    while (tot_vertexes--) {
        birds.erase(birds.find(t->getElem()));
        t->remove(t->getElem(), reinterpret_cast<Tree *&>(t));
    }
    t = nullptr;
    t = new SyncedTrees;
    t->init();
    draw_tree(t);
    x->deleteLater();
    delete x;
    x = nullptr;
}

void Ui_MainWindow::remrndHandler() {
    auto n_ = x->lineEdit->text().toStdString();
    if (n_.empty() || n_ == "-") {
        return;
    }
    int n = std::stoi(n_);
    std::unordered_set<int> vxes;
    std::queue<Tree*> q;
    Tree* w = t;
    do {
        if (w != nullptr) {
            if (w->getElem() != 1.1e9) {
                vxes.insert(w->getElem());
                q.push(w->getLeft());
                q.push(w->getRight());
            }
        }
        w = q.front(); q.pop();
    } while (!q.empty());

    int nm = std::min(tot_vertexes, n);
    std::vector tmp(vxes.begin(), vxes.end());
    std::shuffle(tmp.begin(),
                 tmp.end(),
                 std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    for (int i = 0; i < nm; ++i) {
        birds.erase(birds.find(tmp[i]));
        t->remove(tmp[i], reinterpret_cast<Tree *&>(t));
    }
    tmp.clear();
    vxes.clear();

    draw_tree(t);

    x->deleteLater();
    delete x;
    x = nullptr;
}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        if (event->modifiers() == Qt::ShiftModifier) {
            qDebug() << "Custom item left clicked with shift key.";

            // add the item to the selection

            setSelected(true);
        } else if (event->modifiers() == Qt::AltModifier){
            qDebug() << "Custom item left clicked with alt key.";

            // resize the item

            double radius = boundingRect().width() / 2.0;
            _center = QPointF(boundingRect().topLeft().x() + pos().x() + radius,
                              boundingRect().topLeft().y() + pos().y() + radius);
            QPointF pos = event->scenePos();
            qDebug() << boundingRect() << radius << this->pos() << pos << event->pos();
            double dist = sqrt(pow(_center.x() - pos.x(),
                                   2) + pow(_center.y() - pos.y(), 2));
            if (dist / radius > 0.8) {
                qDebug() << dist << radius << dist / radius;
                _isResizing = true;
            } else {
                _isResizing = false;
            }
        } else {
            qDebug() << "Custom item left clicked.";
            QGraphicsItem::mousePressEvent(event);
            event->accept();

            auto x = new ThirdWindow;
            x->connect(n, parent);
            x->show();
        }
    } else if (event->button() == Qt::RightButton) {
        qDebug() << "Custom item right clicked.";
        event->ignore();
    }
}

void CustomItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    if (event->modifiers() == Qt::AltModifier && _isResizing) {
        _isResizing = false;
    } else if (event->modifiers() != Qt::ShiftModifier) {
        QGraphicsItem::mouseReleaseEvent(event);
    }
}

int CustomItem::type() const {
    // Enable the use of qgraphicsitem_cast with this item.
    return UserType+1;
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    qDebug() << "Custom scene clicked.";
    QGraphicsScene::mousePressEvent(event);
    if (!event->isAccepted()) {
        if (event->button() == Qt::LeftButton) {
            is_moving = true;
            base = {event->screenPos().x(), event->screenPos().y()};
            cords.clear();
            for (auto obj: items()) {
                cords.emplace_back(obj->x(), obj->y());
            }
        } else if (event->button() == Qt::RightButton) {
            // check whether there is an item under the cursor
            QGraphicsItem* itemToRemove = nullptr;
                    foreach (auto item, items(event->scenePos())) {
                    if(item->type() == QGraphicsItem::UserType + 1) {
                        itemToRemove = item;
                        break;
                    }
                }
            if (itemToRemove) {
                // remove the item from the graphicsScene
                removeItem(itemToRemove);
            }
        }
    }
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsScene::mouseMoveEvent(event);

    if (is_moving) {
        int dx = event->screenPos().x() - base.first;
        int dy = event->screenPos().y() - base.second;
        int i = 0;
        for (auto obj: items()) {
            obj->setPos(cords[i].first + dx, cords[i].second + dy);
            i++;
        }
    }

}

void CustomScene::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Backspace) {
        // remove all selected items
        qDebug() << "selected items" << selectedItems().size();
        while (!selectedItems().isEmpty()) {
            removeItem(selectedItems().front());
        }
    } else {
        QGraphicsScene::keyPressEvent(event);
    }
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsScene::mouseReleaseEvent(event);
    is_moving = false;
}

ThirdWindow::ThirdWindow() {
    this->resize(348, 110);
    gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QString::fromStdString("gridLayout"));
    label = new QLabel(this);
    label->setObjectName(QString::fromStdString("label"));
    label->setText("Текущее значение:");

    gridLayout->addWidget(label, 0, 0, 1, 1);

    lineEdit = new QLineEdit(this);
    lineEdit->setObjectName(QString::fromStdString("lineEdit"));
    lineEdit->setReadOnly(true);

    gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

    label_2 = new QLabel(this);
    label_2->setObjectName(QString::fromStdString("label_2"));
    label_2->setText("Новое значение:");

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    lineEdit_2 = new QLineEdit(this);
    lineEdit_2->setObjectName(QString::fromStdString("lineEdit_2"));
    auto* val = new QRegExpValidator(QRegExp("0|-?[123456789]\\d{1,8}"));
    lineEdit_2->setValidator(val);

    gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

    pushButton = new QPushButton(this);
    pushButton->setObjectName(QString::fromStdString("pushButton"));
    pushButton->setText("Обновить значение");

    gridLayout->addWidget(pushButton, 2, 0, 1, 1);

    pushButton_2 = new QPushButton(this);
    pushButton_2->setObjectName(QString::fromStdString("pushButton_2"));
    pushButton_2->setText("Удалить вершину");

    gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

    QMetaObject::connectSlotsByName(this);
}

void ThirdWindow::connect(int arg, Ui_MainWindow* p) {
    parent = p;
    n = arg;
    lineEdit->setText(QString::fromStdString(std::to_string(n)));


    QObject::connect(pushButton_2, SIGNAL(released()), this, SLOT(remHandler()));
    QObject::connect(pushButton, SIGNAL(released()), this, SLOT(updHandler()));
}

void ThirdWindow::remHandler() {
    parent->t->remove(n, reinterpret_cast<Tree *&>(parent->t));
    parent->birds.erase(parent->birds.find(n));
    parent->draw_tree(parent->t);
    deleteLater();
}

void ThirdWindow::updHandler() {
    auto text = lineEdit_2->text().toStdString();
    if (text.empty() || text == "-") {
        return;
    }
    parent->t->remove(n, reinterpret_cast<Tree *&>(parent->t));
    if (parent->t->bst_tree == nullptr) {
        delete parent->t;
        parent->t = nullptr;
        parent->t = new SyncedTrees;
        parent->t->init();
    }
    int elem = std::stoi(text);
    parent->t->insert(elem, reinterpret_cast<Tree *&>(parent->t));
    parent->birds[elem] = parent->birds[n];
    parent->birds.erase(parent->birds.find(n));
    parent->draw_tree(parent->t);
    deleteLater();
}

void ClickableLabelUpd::mousePressEvent(QMouseEvent*) {
    auto text = lbl->text().toStdString();
    if (text.empty() || text == "-") {
        return;
    }
    parent->t->remove(elem, reinterpret_cast<Tree *&>(parent->t));
    if (parent->t->bst_tree == nullptr) {
        delete parent->t;
        parent->t = nullptr;
        parent->t = new SyncedTrees;
        parent->t->init();
    }
    int nelem = std::stoi(text);
    parent->t->insert(nelem, reinterpret_cast<Tree *&>(parent->t));
    parent->birds[nelem] = parent->birds[elem];
    parent->birds.erase(parent->birds.find(elem));
    parent->ignore = this;
    parent->deleting = true;
    parent->draw_tree(parent->t);
}

void ClickableLabelUpd::mouseMoveEvent(QMouseEvent*) {
    QImage image("/Users/user/Downloads/Webp.net-resizeimage-3.png");
    QPainter p;
    p.begin(&image);
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.fillRect(image.rect(), QColor(0, 0, 0, 255));
    p.end();
    this->setPixmap(QPixmap::fromImage(image));
}

void ClickableLabelUpd::leaveEvent(QEvent*) {
    QImage image("/Users/user/Downloads/Webp.net-resizeimage-3.png");
    QPainter p;
    p.begin(&image);
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.fillRect(image.rect(), QColor(0, 0, 0, 50));
    p.end();
    this->setPixmap(QPixmap::fromImage(image));
}

void ClickableLabelRem::mousePressEvent(QMouseEvent* event) {
    parent->t->remove(elem, reinterpret_cast<Tree *&>(parent->t));
    parent->birds.erase(parent->birds.find(elem));
    parent->ignore = this;
    parent->deleting = true;
    parent->draw_tree(parent->t);
}

void ClickableLabelRem::mouseMoveEvent(QMouseEvent*) {
    QImage image("/Users/user/Downloads/Webp.net-resizeimage-4.png");
    QPainter p;
    p.begin(&image);
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.fillRect(image.rect(), QColor(0, 0, 0, 255));
    p.end();
    this->setPixmap(QPixmap::fromImage(image));
}

void ClickableLabelRem::leaveEvent(QEvent*) {
    QImage image("/Users/user/Downloads/Webp.net-resizeimage-4.png");
    QPainter p;
    p.begin(&image);
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.fillRect(image.rect(), QColor(0, 0, 0, 50));
    p.end();
    this->setPixmap(QPixmap::fromImage(image));
}

void ClickableLineEdit::focusInEvent(QFocusEvent* e) {
    QLineEdit::focusInEvent(e);
    QTimer::singleShot(0, this, &QLineEdit::selectAll);
}
