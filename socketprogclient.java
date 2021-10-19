import java.io.*;
import java.util.*;
import java.net.*;


class Test{

    public static void main(String args[])throws Exception
    {
        ServerSocket s1=new ServerSocket(1356);
        Socket ss=s1.accept();
        Scanner sc=new Scanner(ss.getInputStream());
        int temp=sc.nextInt();
        temp=temp*2;
        PrintStream p=new PrintStream(ss.getOutputStream());
        p.println(temp);
    }
}
