#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <string>
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

    Node getParticularNode(int indexNode){
        return allNodesInCollection.at(indexNode + 1);
    }
private:

    void setAllNodesInCollection(){
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
    int destinationLayerIndex;
    int nodesInDestination;
    int nodesInStart;

    //constructor - with setAmountOfWeights called

public:

    WeightLayerCollection(int destinationLayerIndex, int nodesInDestination, int nodesInStart) : destinationLayerIndex(
            destinationLayerIndex), nodesInDestination(nodesInDestination), nodesInStart(nodesInStart) {}
//    WeightLayerCollection(int destinationLayer, int nodesInDestination, int nodesInStart) : destinationLayerIndex(
//            destinationLayer), nodesInDestination(nodesInDestination), nodesInStart(nodesInStart) {
//      //  generateWeightNodeMap();
//    }

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

    static string splitStringAtCharacter(string s, string del, int indexToReturn) // https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
    {
        int start, end = -1*del.size();
        do {
            start = end + del.size();
            end = s.find(del, start);
            string firstString = s.substr(start, end - start);
            string endString = s.substr(end - start + 1, end);
            string strings[] = {firstString, endString};
            if (indexToReturn == 0) {
                return firstString;
            } else if (indexToReturn == 1) {
                return endString;}
        } while (end != -1);
    }

    vector<Weight> setInitialAllWeightsLayerStartToDestination() { //sets the initial weights
        for(int i = 0; i < amountOfWeights; i++){
            Weight weight(destinationLayerIndex - 1, destinationLayerIndex);
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

    void getStartLayerNode(string nodePair){

       // int myint1 = stoi(str1)
    }

    void performGradientDescent(Layer inputLayer, Layer outputLayer, double expectedOutput[]){ //unfinished
        //iterate through the map
        for (auto itr = mapWeightsCorrespondingNodes.begin(); itr != mapWeightsCorrespondingNodes.end(); ++itr) {
          //  string nodePair = itr->first;
            string nodeIndexStart = splitStringAtCharacter(itr->first, ":", 0);
            string nodeIndexFinish = splitStringAtCharacter(itr->first, ":", 1);
            Node startNode = inputLayer.getParticularNode(stoi(nodeIndexStart));
            Node finishNode = inputLayer.getParticularNode(stoi(nodeIndexFinish));
            Weight weight = itr->second;
            double derivative;
            if(destinationLayerIndex == 0){
                double aLMin1 = startNode.getActivation();
                double aL = finishNode.getActivation();
                double y = expectedOutput[stoi(nodeIndexFinish) + 1];
                double zL = finishNode.getZl();
                double sigmoidDeriv = finishNode.sigmoidFunction(zL) * ( 1 - finishNode.sigmoidFunction(zL));
                derivative = 2 * aLMin1 * (aL - y) * sigmoidDeriv;
            }


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
    // outputLayer.performGradientDescent();//




    return 0;
}

//TO DO
// communicate with the layer to get the relevant index
