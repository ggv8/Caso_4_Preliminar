# include <iostream>
# include <ctime>
# include "ADT/List.h"
# include "ADT/Tree.h"
# include "Door.h"
# include "PathFinder.h"

# define TOTAL_DOORS 12

using namespace std;

void printNodes(TreeNode<Door>* pNode, int pRecursionLvl) {
    List<TreeNode<Door>>* list = pNode->children;
    Door* data = pNode->data;

    // Identacion inicial segun nivel de recursion
    cout << "\n";
    for (int times = 0; times < pRecursionLvl; ++times) {
        cout << "    ";
    }

    // Print de cada child node
    cout << data->getID() << ":[";
    for(int i = 0; i < list->getSize(); i++) {
        printNodes(list->get(i), pRecursionLvl+1);
        cout << "\n";
    }

    // Identacion final segun nivel de recursion
    if (! list->isEmpty()){
        for (int times = 0; times < pRecursionLvl; ++times) {
            cout << "     ";
        }
    }
    cout << "],";
}

void printTree(Tree<Door>* pTree) {
    printNodes(pTree->getRoot(), 0);
}

Tree<Door>* generateMap() {
    srand(time(NULL));

    Queue<TreeNode<Door>>* nodeQueue = new List<TreeNode<Door>>;
    Tree<Door>* tree = new Tree<Door>;
    TreeNode<Door>* node;

    // Init root door
    Door* newDoor = new Door(0, false);
    tree->add(newDoor, nullptr);

    int tChance, dChance, index;
    dChance = rand() % 3 + 2;   // Rango de 2 a 4 puertas a generar

    // El nodo de cada puerta generada pasa a un queue de espera para generar sus puertas
    for (index=1; dChance > 0; dChance--) {
        tChance = rand() % 2;
        newDoor = new Door(index++, tChance);
        node = tree->add(newDoor, tree->getRoot());
        nodeQueue->enqueue(node);
    }

    while (true) {
        dChance = rand() % 2 + 2;   // Rango de 2 a 3 por nodo, pues ya tienen parent door
        node = nodeQueue->dequeue();
        for (; dChance > 0; --dChance)
        {// Nuevamente, cada puerta generada pasa a un queue para generar sus puertas
            tChance = rand() % 2;
            newDoor = new Door(index++, tChance);
            nodeQueue->enqueue(tree->add(newDoor, node));
            if (index > TOTAL_DOORS)
            {// Finaliza iteracion tras completar cuota de puertas
                return tree;
            }
        }
    }
}

int main() {
    Tree<Door>* map = generateMap();
    printTree(map);

    short choice;
    cout << "\nReady? 1/0: ";
    cin >> choice;
    if (! choice) {
        return 0;
    }
    cout << "\n----------------- _PathFinder_ -----------------" << endl;

    pathFinding(map);
    return 0;
}