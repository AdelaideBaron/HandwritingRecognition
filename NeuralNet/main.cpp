#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <map>

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

class Layer{ //Layer = node collection
    vector<double> inputValues{};
    int layerNumber;
public:
    Layer(const vector<double> &inputValues, int layerNumber) : inputValues(inputValues),
                                                                layerNumber(layerNumber) {setAllNodesInCollection();}

    const vector<double> &getInputValues() const {
        return inputValues;
    }

    int getNoOfNodes(){
        return inputValues.size();
    }

    vector<Node> allNodesInCollection{}; //can this be accessed, and changed, by calling class? Maybe make private?

    const vector<Node> getAllNodesInCollection() const {
      //  setAllNodesInCollection();
        return allNodesInCollection;
    }

    void printAllNodesZLInCollection(){
        for(Node node : allNodesInCollection){
            cout << node.getZl();
        }
    }
private:

    void setAllNodesInCollection(){ // (const vector<Node> &allNodesInCollection) { //run this to make the nodes
       // vector<Node> nodes;
       // Node node(80);

        for(double singleInput : inputValues) {
            Node node(singleInput);
            allNodesInCollection.push_back(node);
        }

       // return allNodesInCollection;
    }
};



class NodesIntoLayers{
    //here we put the nodes into layers? so input array values, and then make a layer
};

class Weight : public error_code {
    //Layer needs to be in the constructor - no, this will be monitored in weight collection
    int indexInPreviousLayer;
    int indexInNextLayer;



public:
    Weight(int indexInPreviousLayer, int indexInNextLayer) : indexInPreviousLayer(
            indexInPreviousLayer), indexInNextLayer(indexInNextLayer){ }

    int getIndexInPreviousLayer() const {
        return indexInPreviousLayer;
    }

    int getIndexInNextLayer() const {
        return indexInNextLayer;
    }

    double getWeightValue() const {
        return weightValue;
    }



//will have the gradient descent bits in here?


private:
    double weightValue = rand() % 11 + (-5);//decided on range [-5,5]
};

class WeightLayerCollection{
    int destinationLayer;
    int nodesInDestination;
    int nodesInStart;

    //constructor - with setAmountOfWeights called

public:
    WeightLayerCollection(int destinationLayer, int nodesInDestination, int nodesInStart) : destinationLayer(
            destinationLayer), nodesInDestination(nodesInDestination), nodesInStart(nodesInStart) {
      //  generateWeightNodeMap();
    }

    void start(){
        setInitialAllWeightsLayerStartToDestination();
        createWeightLabels();
        setWeightsToNodes();
    }

    void updateWeights(){
        //will have to call gradient decent on each weight
    }

    Weight accessParticularWeight(int index){ //to be used above
        return allWeights[index];
    }

// private:
    int amountOfWeights = nodesInDestination * nodesInStart;
     vector<Weight> allWeights;
     vector<double> allWeightValues; //more for monitoring purposes
     vector<string> nodeWeightLabels;
     map<string, Weight> mapWeightsCorrespondingNodes;

    vector<Weight> setInitialAllWeightsLayerStartToDestination() { //sets the initial weights
        for(int i = 0; i < amountOfWeights; i++){
            Weight weight(destinationLayer -1, destinationLayer);
            allWeights.push_back(weight);

            double value = weight.getWeightValue(); //monitoring only
            allWeightValues.push_back(value); //monitoring only

        }

        return allWeights;
    }

    void printWeight(){ //kind of pointless, as what are you printing?
        for (Weight item : allWeights)
            cout << item << "  ";
    }

    void printValues(){
        for (double item : allWeightValues)
            cout << item << " ";
    }

    vector<string> createWeightLabels() { //setting the nodes assigned, e.g. 1, 2 = n_1 in layer L-1, n_2 in layer L
        for(int i = 0; i < nodesInStart; i ++){
            for(int j = 0; j < nodesInDestination; j ++){
                string stringToAdd = to_string(i) + ":" + to_string(j);
                nodeWeightLabels.push_back(stringToAdd);
            }
        }
        return nodeWeightLabels;
    }

    void printNodes(){
        for (string item : nodeWeightLabels)
            cout << item << "  ";
    }

    map<string, Weight> setWeightsToNodes(){
        //eventually, have something in place to ensure the things have been created
        int i = 0;
        for(string nodePair : nodeWeightLabels){
            mapWeightsCorrespondingNodes.insert({nodePair, allWeights[i]});
            i++;
        }

        return mapWeightsCorrespondingNodes;
    }

    void printNodeWeightPairs(){
        cout << "KEY\tELEMENT\n";
        for (auto itr = mapWeightsCorrespondingNodes.begin(); itr != mapWeightsCorrespondingNodes.end(); ++itr) {
            cout << itr->first
                 << '\t' << itr->second << '\n';
        }
    }

    void performGradientDescent(){
        //iterate through the map
        for (auto itr = mapWeightsCorrespondingNodes.begin(); itr != mapWeightsCorrespondingNodes.end(); ++itr) {
           string nodePair = itr->first;
            Weight weight = itr->second;
//            cout << nodePair
//                 << '\t' << itr->second << '\n';
        }


       // switch(indexInNextLayer){
       //     case 0:


      //  }

    }


};


int main() {
    double arr[] = {10.0, 20.0, 30.0};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<double> inputValues(arr, arr + n);

    Layer nodeCollection(inputValues, 0);

    WeightLayerCollection outputLayer(0, 2, 3);

    outputLayer.start();
//    outputLayer.printNodeWeightPairs();
    outputLayer.performGradientDescent();

    return 0;
}

//TO DO
// communicate with the layer to get the relevant index
