import java.util.Scanner;
public class ola {
    public static void main(String[] arg){
        // imprime o Ola mundo
        System.out.print("Content-type: text/html\n\n");
        System.out.print("Ola mundo!<br><br>");
       
	// imprime o tipo request
	String method = System.getenv("REQUEST_METHOD");
        System.out.print("Metodo:"+method);


        // imprime as variaveis GET ou POST
        if (method != null){
                if (method.equals("GET")){
	        String getVARS = System.getenv("QUERY_STRING").replaceAll("&","<br>");
                System.out.print("<BR>Variaveis GET:<BR>"+getVARS);
                }else{
                        System.out.print("<BR>Conteudo POST:<BR>");
                        Scanner s = new Scanner(System.in);
                        while (s.hasNext()){
				String t=s.next().replaceAll("&","<BR>");
                                System.out.print(t);
                        }
                }
        }
    }
}
