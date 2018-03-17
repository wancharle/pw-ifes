import java.util.Scanner;

public class ola {
    public static void main(String[] arg){
        // cabeçalhos padões
        System.out.print("Content-type: text/html\n\n");
        System.out.print("<meta charset='utf-8' />\n");

        // imprime o Ola mundo
        System.out.print("Ola mundo!<br><br>");
        
        imprimeVariaveisDeFormularios();	
    }

    public static void imprimeVariaveisDeFormularios(){
        // imprime o tipo request
        String method = System.getenv("REQUEST_METHOD");
        System.out.print("Metodo:"+method);
       // imprime as variaveis GET ou POST
        if (method != null){
                String getVARS = System.getenv("QUERY_STRING").replaceAll("&","<br>");
                System.out.print("<BR><BR>Variáveis GET:<BR>"+getVARS);
                
                System.out.print("<BR><BR>Variáveis POST:<BR>");
                if (method.equals("POST")){
                        Scanner s = new Scanner(System.in);
                        while (s.hasNext()){
                                String t=s.next().replaceAll("&","<BR>");
                                System.out.print(t);
                        }
                }
        }
    }
}
