// XOR trees
// similar to memeory efficient doubly linked list
// Each nodes left will have the address of the parent and its left children
// Each node right will have the address of the parent and its right children
// The root nodes parent is null and also leaf nodes children are null nodes
// for example:
//             A
//            / \
//           B   C 
//          / \ / 
//         D  E F 
//           /
//          G
// XOR-->
//         NULL+B| A |NULL+C
//          /              \
//       A+D| B |A+E       A+F| C |A+NULL          
//       /          \               /
//  B+NULL|D|B+NULL B+G|E|B+NULL   C+NULL|F|C+NULL
//                   /
//           E+NULL|G|E+NULL