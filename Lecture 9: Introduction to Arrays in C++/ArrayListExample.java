package com.company;

import java.util.ArrayList;
public class ArrayListExample {
    public static void main(String [] args){
        /*
         Array List:
              --> Use to Create Dynamic Arrays
              --> Part of Collection Framework
              --> Something Similar to Vectors in C++
              --> O(1) Time Complexity
         Syntax:
               ArrayList<Integer> list = new ArrayList< * > ( Default Size );
                            /       /            \                   \
                       Generics   Name        Constructor       Initial Capacity

               At Place of * you can define the data Type Integer etc. But not Necessary
               --> Integer is generics
               --> Wrapper Class
               --> We can't Use Primitives in the place of generics that will produce an ERROR!!
               --> he Integer class wraps a value of the primitive type int in an object.
                An object of type Integer contains a single field whose type is int.
         REMEMBER:
                 --> Internally size of Array List is Fixed
                 --> When Array List is Half filled
                 --> Then An Array List Doubles the Size of Previous one is Created
                 --> It will Copy all the Elements in New One
                 --> And Previous One is Deleted
                 --> Time Complexity of Array List = O(1) --> Constant

         */

        // Syntax:
        ArrayList<Integer> list = new ArrayList< >(3);
        list.add(23);
        list.add(78);
        list.add(50);
        list.add(68);
        System.out.println(list);    // [23, 78, 50, 68]
        System.out.println(list.contains(67)); // false
        list.set(2,89);
        System.out.println(list);  // [23, 78, 89, 68]
        list.remove(1);
        System.out.println(list);  // [23, 89, 68]



    }
}
