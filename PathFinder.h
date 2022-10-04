# pragma once
# include <iostream>
# include "ADT/List.h"
# include "ADT/Tree.h"
# include "Door.h"

using namespace std;

template<typename T>
void printList(List<T>* pList) {
    cout << "[";
    for (int index = 0; index < pList->getSize();) {
        Door* data = pList->get(index++)->data;
        cout << data->getID();
        if (index != pList->getSize()) {
            cout << ", ";
        }
    }
    cout << "]";
}

template<typename T>
List<T>* findPending(List<T>* pPathList, List<T>* pClearedList) {
    List<T>* pendingList = new List<T>;
    for (int index = 0; index < pPathList->getSize(); ++index) {
        T* path = pPathList->get(index);
        if (pClearedList->find(path) == NOT_FOUND) {
            pendingList->add(path);
        }
    }
    return pendingList;
}

void pathFinding(Tree<Door>* pDoorMap) {
    List<TreeNode<Door>>* currentList = new List<TreeNode<Door>>;
    Stack<TreeNode<Door>>* currentPath = currentList;
    List<TreeNode<Door>>* clearedOptions = new List<TreeNode<Door>>;

    currentPath->push(pDoorMap->getRoot()); // Push del root path

    while (clearedOptions->getSize() != pDoorMap->getSize()) {
        cout << "Current Path: "; printList(currentList); cout << endl;
        cout << "Cleared Paths: "; printList(clearedOptions); cout << endl;

        // Obtiene children list de stack's top
        List<TreeNode<Door>>* pathList = currentPath->top()->children;
        cout << "\nOptions: "; printList(pathList); cout << endl;

        // Descarta opciones ya revisadas
        pathList = findPending(pathList, clearedOptions);
        bool isCleared = pathList->isEmpty();
        cout << "Is Cleared: " << isCleared << endl;

        if (isCleared) 
        {// Si no hay opciones o ya se descartaron todas
            TreeNode<Door>* discardedPath = currentPath->pop(); // Pop para regresar al path previo
            clearedOptions->add( discardedPath );               // Dicho pop queda enlistado como revisado
            cout << "Cleared Door #" << discardedPath->data->getID() << endl;
        } else {
            int choice = rand() % pathList->getSize();
            TreeNode<Door>* pathChoice = pathList->get(choice); // Selecciona una opcion disponible
            currentPath->push(pathChoice);                      // Push para avanzar al path seleccionado
            cout << "Entered Door #" << pathChoice->data->getID() << endl;
        }
        cout << "------------------------------------------------" << endl;
    }

}