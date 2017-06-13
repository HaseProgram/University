QUnit.test("Add and delete element in queue.", function( assert ) {
  var Queue = new Q();
  Queue.add(100);
  assert.ok(Queue.remove() == "100", "Added 100 and deleted 100, passed!" );
  Queue.add(100);
  Queue.add(200);
  assert.ok(Queue.remove() == "100", "Added 100 and 200, first deleted is 100, passed!" );
  assert.ok(Queue.remove() == "200", "Added 100 and 200, second deleted is 200, passed!" );
  assert.ok(Queue.remove() == false, "Deleting from empty queue return false, passed!" );
});

QUnit.test("Minimum and maximum.", function( assert ) {
  var Queue = new Q();
  Queue.add(100);
  Queue.add(200);
  Queue.add(300);
  Queue.add(-100);
  Queue.add(0);

  assert.ok(Queue.minimum() == "-100", "Queue is: 100, 200, 300, -100, 0; minimum is -100, Passed!" );
  assert.ok(Queue.maximum() == "300", "Queue is: 100, 200, 300, -100, 0; maximum is 300, Passed!" );

  Queue.remove();
  Queue.remove();

  assert.ok(Queue.minimum() == "-100", "Removed 2 last elements. Queue is: 100, 200, 300; minimum is 100, Passed!" );
  assert.ok(Queue.maximum() == "300", "Removed 2 last elements. Queue is: 100, 200, 300; maximum is 300, Passed!" );
});

QUnit.test("Size.", function( assert ) {
  var Queue = new Q();
  Queue.add(100);
  Queue.add(200);
  Queue.add(300);
  Queue.add(-100);
  Queue.add(0);
  assert.ok(Queue.size() == "5", "Queue is: 100, 200, 300, -100, 0; size is 5, Passed!" );
  Queue.add(100);
  assert.ok(Queue.size() == "6", "Added 1 element; size is 6, Passed!" );
  Queue.remove();
  Queue.remove();
  assert.ok(Queue.size() == "4", "Removed 2 elements; size is 4, Passed!" );
});

QUnit.test("Print.", function( assert ) {
  var Queue = new Q();
  Queue.add(100);
  Queue.add(200);
  Queue.add(300);
  Queue.add(-100);
  Queue.add(0);
  assert.ok(Queue.print(true) == "100<br>200<br>300<br>-100<br>0<br>", "Queue is: 100, 200, 300, -100, 0; print is 100<br>200<br>300<br>-100<br>0<br>, Passed!" );
});
