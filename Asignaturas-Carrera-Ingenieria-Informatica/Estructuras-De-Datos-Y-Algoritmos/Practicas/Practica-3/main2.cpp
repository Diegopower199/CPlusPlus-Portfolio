#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
    std::cout << "Expresion: (2*(3+4)-10)/2" << std::endl;

    BinaryTree _34{"+"};
    _34.add_left({"3"});
    _34.add_right({"4"});

    BinaryTree _234{"*"};
    _234.add_left({"2"});
    _234.add_right(_34);

    BinaryTree _m10{"-"};
    _m10.add_left(_234);
    _m10.add_right({"10"});

    BinaryTree expr1{"/"};
    expr1.add_left(_m10);
    expr1.add_right({"10"});

    std::cout << "Notacion infija" << std::endl;
    expr1.dfs_inorder([](const std::string &node)
                      { std::cout << node << " "; });
    std::cout << std::endl;

    std::cout << "Notacion postfija" << std::endl;
    expr1.dfs_postorder([](const std::string &node)
                        { std::cout << node << " "; });

    cout << endl;

    std::cout << "Expresion: - 3 * log (2 + 5)" << std::endl;

    BinaryTree _25{"+"};
    _25.add_left({"2"});
    _25.add_right({"5"});

    BinaryTree log25{"log"};
    log25.add_right(_25);

    BinaryTree _3{"-"};
    _3.add_right({"3"});

    BinaryTree expr{"*"};
    expr.add_left(_3);
    expr.add_right(log25);

    std::cout << "Notacion infija" << std::endl;
    expr.dfs_inorder([](const std::string &node)
                     { std::cout << node << " "; });
    std::cout << std::endl;

    std::cout << "Notacion postfija" << std::endl;
    expr.dfs_postorder([](const std::string &node)
                       { std::cout << node << " "; });
}
