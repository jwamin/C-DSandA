```
4th from end

count 0
next true
1->2->3->4->5
^

count 1
next true
1->2->3->4->5
   ^
count 2
next true
1->2->3->4->5
      ^

if next == false {
    assert, return false // failure case
}

count 3
count == searchIndex, start count2
count2 0
next true
1->2->3->4->5
^        ^
^  

count 4
count2 1
next false
1->2->3->4->5
   ^        ^
   ^

   return count2.value
```