import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/*
ID: chaoswo1
LANG: JAVA
TASK: namenum
*/

/**
 * As we already know,the words in 'dict.txt' is sorted by alphabetical,so
 * we just pick one and check whether it fixes to the number.If matched,
 * print it out by one single line.If none of them fixed,then print out 
 * the word "NONE".
 */
public class namenum {
	static String getNum(String name){
		String num = "";
		for(int i=0;i<name.length();++i){
			char ch=name.charAt(i);
			switch (ch) {
			case 'A':case 'B':case 'C':num+='2';break;
			case 'D':case 'E':case 'F':num+='3';break;
			case 'G':case 'H':case 'I':num+='4';break;
			case 'J':case 'K':case 'L':num+='5';break;
			case 'M':case 'N':case 'O':num+='6';break;
			case 'P':case 'R':case 'S':num+='7';break;
			case 'T':case 'U':case 'V':num+='8';break;
			case 'W':case 'X':case 'Y':num+='9';break;

			default:
				break;
			}
		}
		return num;
	}
	public static void main(String[]args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("namenum.in"));
		BufferedReader din=new BufferedReader(new FileReader("dict.txt"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("namenum.out")));
		String num=in.readLine();
		boolean none=true;
		while(true){
			String name=din.readLine();
			if(name==null) break;
			if(num.equals(getNum(name))){
				out.println(name);
				none=false;
			}
		}
		if(none) out.println("NONE");
		out.close();
		System.exit(0);
	}

}
