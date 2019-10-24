import java.io.*;
import java.util.*;
import java.net.*;


class Test{

    public static void main(String args[])throws Exception
    {
        Socket s=new Socket("192.168.0.108",1356);
        Scanner sc=new Scanner(System.in);
        Scanner sc1=new Scanner(s.getInputStream());
        System.out.println("Enter a number to be doubled");
        int n=sc.nextInt();

        PrintStream p=new PrintStream(s.getOutputStream());
        p.println(n);

        System.out.println(sc1.nextInt());
    }
}
