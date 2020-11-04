#include "UIstuff/mw.h"
#include "Trees/syncedtrees.h"

int main(int argc, char *argv[]) {
    srand(41u);
    QApplication a(argc, argv);
    Ui_MainWindow window{};
    auto* w = new QMainWindow();
    window.setupUi(w);
    w->show();

    auto* tree = new SyncedTrees;
    tree->init();

    window.t = tree;
//    window.t->insert(5, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(4, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(7, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(3, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(6, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(34, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(56, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(1, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(3, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(23, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(43, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(54, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(122, reinterpret_cast<Tree *&>(window.t));
//    window.t->insert(213, reinterpret_cast<Tree *&>(window.t));

//    tree->insert(10, reinterpret_cast<Tree *&>(tree));
//    tree->insert(11, reinterpret_cast<Tree *&>(tree));
//    tree->insert(12, reinterpret_cast<Tree *&>(tree));
//    tree->insert(13, reinterpret_cast<Tree *&>(tree));
//    tree->insert(14, reinterpret_cast<Tree *&>(tree));

//    tree->_insert(12, tree);
//    tree->_insert(40, tree);
//    tree->_insert(4, tree);
//    tree->_insert(24, tree);
//    tree->_insert(16, tree);
//    tree->_insert(28, tree);
//    tree->_insert(52, tree);
//    tree->_insert(36, tree);
//    tree->_insert(48, tree);
//    tree->_insert(44, tree);
//    tree->_insert(38, tree);
//    tree->_insert(42, tree);
//    tree->_insert(39, tree);
//    tree->_insert(41, tree);
//    tree->_insert(1000000201, tree);
//    tree->_insert(1000000001, tree);
    window.draw_tree(tree);
    a.exec();
    return 0;
//    QApplication a(argc, argv);
//    CustomItem item;
//    item.setRect(20, 20, 60, 60);
//    item.setFlags(QGraphicsItem::ItemIsSelectable|
//                  QGraphicsItem::ItemIsMovable);
//    CustomScene scene;
//    scene.setSceneRect(0, 0, 500, 500);
//    scene.addItem(&item);
//    QGraphicsView view;
//    view.setScene(&scene);
//    view.show();
//    return a.exec();
}

//#include "Trees/syncedtrees.h"
//
//int main() {
//    srand(time(nullptr));
//
//    SyncedTrees tree;
//    tree.insert(8);
//    tree.insert(3);
//    tree.insert(10);
//    tree.insert(1);
//    tree.insert(6);
//    tree.insert(4);
//    tree.insert(7);
//    tree.insert(13);
//    tree.insert(9);
//    tree.insert(12);
//    tree.insert(11);
//
//    tree.remove(8);
//
//    std::cout << "hello" << std::endl;
//    return 0;
//}
