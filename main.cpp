#include "UIstuff/mw.h"
#include "Trees/syncedtrees.h"

int main(int argc, char *argv[]) {
    srand(41u);
    QApplication a(argc, argv);
    Ui_MainWindow window{};
    auto *w = new QMainWindow();
    window.setupUi(w);
    w->show();

    auto *tree = new SyncedTrees;
    tree->init();

    window.t = tree;
    window.draw_tree(tree);
    a.exec();
    return 0;
}