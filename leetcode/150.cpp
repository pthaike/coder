/***
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


**/

/**
java
*/

/**
public class Solution {
    public int evalRPN(String[] tokens) {
        if(tokens.length==0)
            return 0;
        Stack<Integer> s = new Stack<Integer>();
        for(String t:tokens)
        {
            if(t.equals("+"))
            {
                int a2 = s.pop();
                int a1 = s.pop();
                a1 = a1+a2;
                s.push(a1);
            }
            else if(t.equals("-"))
            {
                int a2 = s.pop();
                int a1 = s.pop();
                a1 = a1-a2;
                s.push(a1);
            }
            else if(t.equals("*"))
            {
                int a2 = s.pop();
                int a1 = s.pop();
                a1 = a1*a2;
                s.push(a1);
            }
            else if(t.equals("/"))
            {
                int a2 = s.pop();
                int a1 = s.pop();
                a1 = a1/a2;
                s.push(a1);
            }
            else
            {
                s.push(Integer.parseInt(t));
            }
        }
        return s.pop();
    }
}
*/
