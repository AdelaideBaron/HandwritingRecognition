A collection of the unofficial tests written along the way to support development. 

_Testing Node class, currently only the Node class exists_
```
    Node node(10.0);
    cout << node.getActivation();
```

_Testing the creation of Layer, the constructor, and methods within. Only Node class and Layer exist._
```
    double arr[] = {10.0, 20.0, 30.0}; //a simple vector to test the inputs for now 
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<double> inputValues(arr, arr + n);

    Layer nodeCollection(inputValues);

    for (double i : nodeCollection.getInputValues())
        cout << i << ", ";

    cout << nodeCollection.getNoOfNodes();
```

_Testing the creation of nodes & their ZL in the collection_ 
```
   vector<double> inputValues(arr, arr + n);

    Layer nodeCollection(inputValues);

   // for (double i : nodeCollection.getInputValues())
     //   cout << i << ", ";

    cout << nodeCollection.getNoOfNodes();

    nodeCollection.setAllNodesInCollection();
    // nodeCollection.getNoOfNodes();
    nodeCollection.printAllNodesZLInCollection(); //YAY 
```

_Testing individual weight creation_ 
```
Weight weight1(1,2);
    cout << weight1.getWeightValue();
```

_Collection of weights for a layer, checking the amount of weights_ 
``` 
WeightLayerCollection outputLayer(0, 2, 3);
    cout << outputLayer.amountOfWeights; 
    
\\and the amount created 

WeightLayerCollection outputLayer(0, 2, 3);
  //  cout << outputLayer.amountOfWeights;
    outputLayer.setInitialAllWeightsLayerStartToDestination();
    
    cout << outputLayer.allWeights.size();
```

_Node creation, and putting the methods into one start method_ 
```
outputLayer.start();
    cout << outputLayer.nodeWeightLabels.size();
    
```

_Verifying the nodes created_ 
```  outputLayer.setWeightsToNodes(outputLayer.nodeWeightLabels, outputLayer.allWeights);
    outputLayer.printNodes(); 
```

_Ensuring the weights are different by assessing their value_ 
```
  WeightLayerCollection outputLayer(0, 2, 3);

    outputLayer.start();
    outputLayer.setWeightsToNodes(); //outputLayer.nodeWeightLabels, outputLayer.allWeights);
  //  outputLayer.printNodes(); // issue must lie in nodes as they're all identical
   // outputLayer.printWeight();
    // outputLayer.printNodeWeightPairs();
    outputLayer.printNodeWeightPairs();
    outputLayer.printValues(); 

```

_Testing string splitter_ 
``` 
cout << outputLayer.splitStringAtCharacter("hello:you", ":", 1);
```