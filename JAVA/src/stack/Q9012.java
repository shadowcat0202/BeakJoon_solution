package stack;

import java.io.*;
import java.util.Scanner;
import java.util.Stack;

public class Q9012 {
    public Q9012(){
        try {
            System.setIn(new FileInputStream(System.getProperty("user.dir")+"\\src\\input\\Q9012.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void Solution(){
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());

        while(N-- > 0){
            if(VPS(sc.nextLine())) System.out.println("YES");
            else System.out.println("NO");
        }
    }

    private boolean VPS(String line){
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < line.length(); i++){
            char c = line.charAt(i);
            if(c == ')'){
                if(stack.isEmpty()) return false;
                else stack.pop();
            }
            else{
                stack.push(c);
            }
        }
        if(!stack.isEmpty()) return false;
        else return true;
    }

    private boolean VPS_ex(String line){
        int size = 0;
        for(int i = 0; i < line.length(); i++){
            char c = line.charAt(i);
            if(c == ')'){
                if(size <= 0) return false;
                else size++;
            }
            else{
                size--;
            }
        }
        if(size > 0) return false;
        else return true;
    }




}
