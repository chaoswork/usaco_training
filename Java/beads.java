import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/*
ID: chaoswo1
LANG: JAVA
TASK: beads
*/

/**
you can append the given string,so it looks like a longer necklace.
then find the point from left to right,determine the best point to 
get the longest substring as the problem said.
*/
public class beads {
	public static void main(String[]args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("beads.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
		
		int n=Integer.parseInt(in.readLine());
		String necklace=in.readLine();
		necklace+=necklace;
		int best=0;
		
		for(int p=0;p<necklace.length();++p){
			int maxlen=0;
			int i;
			for(i=p;i>=0;i--)//from p to i,red
				if(necklace.charAt(i)=='b') break;
			maxlen+=p-i;
			for(i=p+1;i<necklace.length();++i)//from p+1 to i,blue
				if(necklace.charAt(i)=='r') break;
			maxlen+=i-p-1;
			if(best<maxlen)best=maxlen;
			
			maxlen=0;
			for(i=p;i>=0;i--)//from p to i,blue
				if(necklace.charAt(i)=='r')break;
			maxlen+=p-i;
			for(i=p+1;i<necklace.length();++i)//from p+1 to i,red
				if(necklace.charAt(i)=='b')break;
			maxlen+=i-p-1;
			if(best<maxlen)best=maxlen;
		}
		if(best>n) best=n;
		out.println(best);
		out.close();
		System.exit(0);
	}
}
