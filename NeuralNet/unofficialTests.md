A collection of the unofficial tests written along the way to support development. 

_Testing Node class, currently only the Node class exists_
```
    Node node(10.0);
    cout << node.getActivation();
```

_Testing the creation of NodeCollection, the constructor, and methods within. Only Node class and NodeCollection exist._
```
    double arr[] = {10.0, 20.0, 30.0}; //a simple vector to test the inputs for now 
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<double> inputValues(arr, arr + n);

    NodeCollection nodeCollection(inputValues);

    for (double i : nodeCollection.getInputValues())
        cout << i << ", ";

    cout << nodeCollection.getNoOfNodes();
```