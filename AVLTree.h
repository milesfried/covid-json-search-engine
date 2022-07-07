//
// Created by Steve Ntare on 6/21/2021.
//

#include "DSVector.h"
#include <iomanip>
#include <iostream>
#include "DSString.h"

#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_AVLTREE_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_AVLTREE_H

using namespace std;

//We used the AVL Tree implementation found at the following URL for inspiration:
// http://www.cs.sjsu.edu/~shaverdian/AVLTreesLecture.pdf
template<typename T>
class AVLTree {
private:
    int size= 0;
    struct MSNode {
        T key;


        DSVector<DSString> data;
        MSNode *left;
        MSNode *right;
        int height;

        MSNode(T x, MSNode *lst, MSNode *rst, int h = 0) : key(x), left(lst), right(rst), height(h) {}

        void add(DSString input) {
            data.push_back(input);
        }

        void print() {
            cout << "Printing Node: " << key << endl;
            for (int i = 0; i < data.getSize(); i++) {
                cout << "\t- " << data[i] << endl;
            }
        }
    };
    MSNode *root;

    void insert(T x, MSNode *&t) {

        if (t == nullptr) {
            t = new MSNode(x, nullptr, nullptr);
        } else if (x < t->key) {
            insert(x, t->left);
            if (height(t->left) - height(t->right) == 2) {
                if (x < t->left->key) {
                    singleLeftRotate(t);
                } else {
                    doubleLeftRotate(t);
                }
            }
        } else if (x > t->key) {
            insert(x, t->right);
            if (height(t->right) - height(t->left) == 2) {
                if (x > t->right->key) {
                    singleRightRotate(t);
                } else {
                    doubleRightRotate(t);
                }
            }
        }
        t->height = max(height(t->left), height(t->right)) + 1;
    }


    void singleRightRotate(MSNode *&k2) {
        MSNode *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k2 = k1;
    };

    void singleLeftRotate(MSNode *&k2) {
        MSNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k2 = k1;
    };

    void doubleRightRotate(MSNode *&k3) {
        singleLeftRotate(k3->right);
        singleRightRotate(k3);
    };

    void doubleLeftRotate(MSNode *&k3) {
        singleRightRotate(k3->left);
        singleLeftRotate(k3);
    };

    static int height(MSNode *t) {
        return t == nullptr ? -1 : t->height;
    }

    void printPrivate(MSNode *input) {
        if (input == nullptr) {
            return;
        }
        if (input == root) {
            if (input->left == nullptr && input->right == nullptr) {
                cout << input->key << " root " << endl;
            } else if (input->left == nullptr) {
                cout << input->key << " root " << input->right->key << " right" << endl;
            } else if (input->right == nullptr) {
                cout << input->key << " root " << input->left->key << " left" << endl;
            } else {
                cout << input->key << " root " << input->left->key << " left " << input->right->key << " right" << endl;
            }
        } else if (input->left == nullptr && input->right == nullptr) {
            cout << input->key << " leaf " << endl;
        } else if (input->left == nullptr) {
            cout << input->key << " node " << input->right->key << " right" << endl;
        } else if (input->right == nullptr) {
            cout << input->key << " node " << input->left->key << " left" << endl;
        } else {
            cout << input->key << " node " << input->left->key << " left " << input->right->key << " right" << endl;
        }
        printPrivate(input->left);
        printPrivate(input->right);
    }

    void searchTree(T key, MSNode *&input, MSNode *&temp, bool& found) {
        if (input == nullptr) {
            found = false;
            return;
        } else if (input->key == key) {
            temp = input;
            found = true;

        } else if (key < input->key) {
            searchTree(key, input->left, temp, found);
        } else{
            searchTree(key, input->right, temp, found);
        }
    }

public:
    AVLTree() {
        root = nullptr;
    };

    void add(T x) {
        insert(x, root);
        size++;
    }

    static void clear(MSNode *input) {
        if (input == nullptr) {
            return;
        }
        clear(input->left);
        clear(input->right);
        delete input;

    }

    void clear() {
        clear(root);
        size = 0;
        root = nullptr;
    }

    void print() {
        printPrivate(root);
    }

    void addToNode(T& key, DSString& input) {
        MSNode *temp;
        searchTree(key, root, temp);
        temp->add(input);
    }

    void find(T& key, bool& found) {
        MSNode *temp = nullptr;
        searchTree(key, root, temp, found);
        //if (temp != nullptr) return temp->key;
    }

    bool find_val(T& search_key, T& ret_val) {
        MSNode* temp = nullptr;
        bool found = false;
        searchTree(search_key, root, temp, found);
        if(found)
            ret_val = temp->key;
        return found;

    }
    int getSize(){return size;}
};





#endif //SU21_SRCH_ENG_MILES_AND_STEVE_AVLTREE_H
