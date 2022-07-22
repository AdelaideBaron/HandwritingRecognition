#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Node{
    double zL;
public:

    Node(double zL) : zL(zL) {}

    double getZl() const {
        return zL;
    }

    double getActivation(){
        return setActivation();
    }

    double sigmoidFunction(double x) {
        return 1 / (1 + exp(-1 * x));
    }


private:
    double aL;
    double setActivation(){
        aL = sigmoidFunction(zL);
        return aL;
    }


};

class NodeCollection{
    vector<double> inputValues{};
public:
    NodeCollection(const vector<double> &inputValues) : inputValues(inputValues) {};

    const vector<double> &getInputValues() const {
        return inputValues;
    }

    int getNoOfNodes(){
        return inputValues.size();
    }

    vector<Node> allNodesInCollection{};

    const vector<Node> &getAllNodesInCollection() const {
        return allNodesInCollection;
    }

    vector<Node> setAllNodesInCollection(const vector<Node> &allNodesInCollection) {
        vector<Node> nodes;
        Node node(80);

        for(double singleInput : inputValues)
            Node node(singleInput);
            nodes.push_back(node);

        return nodes;
    }


};


int main() {
    double arr[] = {10.0, 20.0, 30.0};
    int n = sizeof(arr) / sizeof(arr[0]);



    vector<double> inputValues(arr, arr + n);

    NodeCollection nodeCollection(inputValues);

    for (double i : nodeCollection.getInputValues())
        cout << i << ", ";

    cout << nodeCollection.getNoOfNodes();

    return 0;


}
