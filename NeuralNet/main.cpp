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

class NodeCollection{ //node collections are essentially layers
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

    const vector<Node> getAllNodesInCollection() const {
      //  setAllNodesInCollection();
        return allNodesInCollection;
    }

    void printAllNodesZLInCollection(){
        for(Node node : allNodesInCollection){
            cout << node.getZl();
        }
    }

    vector<Node> setAllNodesInCollection(){ // (const vector<Node> &allNodesInCollection) {
       // vector<Node> nodes;
       // Node node(80);

        for(double singleInput : inputValues) {
            Node node(singleInput);
            allNodesInCollection.push_back(node);
        }

        return allNodesInCollection;
    }
};

class Layer{
    //all layers have a label (e.g. output), but this will just be the name. We need to know the layer however to perform gradient descent
    // so... perhaps have an input of...
    //input Node collection into Layers
    //for now, we just have NodeCollection as a layer - as they are essentially the same thing

};

class NodesIntoLayers{
    //here we put the nodes into layers? so input array values, and then make a layer
};

class Weight{
    //Layer needs to be in the constructor
    int indexInPreviousLayer;
    int indexInNextLayer;
    double intialValueRange;

public:
    Weight(int indexInPreviousLayer, int indexInNextLayer, double intialValueRange) : indexInPreviousLayer(
            indexInPreviousLayer), indexInNextLayer(indexInNextLayer), intialValueRange(intialValueRange) {}


private:
    double setInitialValue(){
        //generate random number
    }
};


int main() {
    double arr[] = {10.0, 20.0, 30.0};
    int n = sizeof(arr) / sizeof(arr[0]);



    vector<double> inputValues(arr, arr + n);

    NodeCollection nodeCollection(inputValues);

   // for (double i : nodeCollection.getInputValues())
     //   cout << i << ", ";

    cout << nodeCollection.getNoOfNodes();

    nodeCollection.setAllNodesInCollection();
    // nodeCollection.getNoOfNodes();
    nodeCollection.printAllNodesZLInCollection(); //YAY



    return 0;


}
