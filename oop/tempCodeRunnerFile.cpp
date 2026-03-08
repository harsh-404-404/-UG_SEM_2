
    data.addStart(1);
    data.addStart(2);
    data.addStart(3);
    data.addStart(4);
    data.addEnd(0);
    data.insertAt(99,2);
    data.printList();

    data.removeEnd();
    data.removeAt(0);
    data.printList();

    data.removeAt(data.search(99));
    data.printList();
    data.update(99,2);
    data.printList();