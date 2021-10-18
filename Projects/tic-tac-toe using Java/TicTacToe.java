import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 *
 * @author GanapriyaS
 */
public class TicTacToe implements ActionListener{
    JButton jb1[];
    String o;
    String x;
    JButton j6;
    JButton j7;
    JTextField j2;
    JTextField j3;
    JFrame j1;
    JFrame j;
    String s;
    int count=0;
    boolean flag=false;
    Color color;
    TicTacToe()
    {   
        j1=new JFrame("TIC-TAC-TOE");
        j=new JFrame("TIC-TAC-TOE");
        j.setSize(450,487);
        j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        j.setLocationRelativeTo(null);
        j.setLayout(new GridLayout(3,2));
        j1.setSize(250,250);
        j1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        j1.setLocationRelativeTo(null);
        j1.setLayout(new GridLayout(3,2));
        JLabel j4=new JLabel("Enter Player A(X)");
        j1.add(j4);
        j2=new JTextField();
        j1.add(j2);
        JLabel j5=new JLabel("Enter Player B(O)");
        j1.add(j5);
        j3=new JTextField();
        j1.add(j3);
        j6=new JButton("START");
        j1.add(j6);
        j6.addActionListener(this);
        j7=new JButton("STOP");
        j1.add(j7);
        j7.addActionListener(this);
        jb1=new JButton[9];
        for(int i=0;i<jb1.length;i++)
            jb1[i]=new JButton();
        for (JButton jb11 : jb1) {
            j.add(jb11);
            jb11.addActionListener(this);
        }  
         j.setVisible(true);
         j1.setVisible(true);
    }
    public static void main(String []args)
    {
        new TicTacToe();
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {   
        if(e.getSource()==j6)
        {
            x=j2.getText();
            o=j3.getText();
            JOptionPane.showMessageDialog(j1,"GAME STARTS");
            j1.setVisible(false);
            return;
        }
        else if(e.getSource()==j7)
        {
            JOptionPane.showMessageDialog(j1,"GAME ENDS");
            System.exit(0);
        }
        Font f=new Font("Arial",1,60);
        if(count%2==0)
        {
            s="X";
            color=Color.BLACK;
        }
        else
        {
            s="O";
            color=Color.WHITE;
        }
        for (JButton jb11 : jb1) {
            if (e.getSource() == jb11) {
                jb11.setText(s);
                jb11.setFont(f);
                jb11.setBackground(color);
                jb11.setEnabled(false);
            }
        }
        count=count+1;
        win();
    }
    public void win()
    {   
        int a[]={0,3,6};
        for(int i:a)
                if (!jb1[i].getText().equals("") && jb1[i].getText().equals(jb1[i+1].getText()) && jb1[i+1].getText().equals(jb1[i+2].getText())) 
                {
                    flag=true;
                    break;
                }
        int b[]={0,1,2};
        for(int i:b)
                if (!jb1[i].getText().equals("") && jb1[i].getText().equals(jb1[i+3].getText()) && jb1[i+3].getText().equals(jb1[i+6].getText())) 
                {   
                    flag=true;
                    break;
                }
        if (!jb1[4].getText().equals("")&& ((jb1[0].getText().equals(jb1[4].getText()) && jb1[8].getText().equals(jb1[4].getText()))||(jb1[2].getText().equals(jb1[4].getText()) && jb1[4].getText().equals(jb1[6].getText()))))
                flag=true;
        restart();
    }
    void restart()
    {   
        int i=-1;
        if(flag==true)
        {   
            if(s.equals("X"))
                JOptionPane.showMessageDialog(j,x+" WINS");
            else if(s.equals("O"))
                JOptionPane.showMessageDialog(j,o+" WINS");
            i=JOptionPane.showConfirmDialog(j,"RESTART THE GAME");
        }
        else if(count==9)
        {
            JOptionPane.showMessageDialog(j,"MATCH DRAWS");
            i=JOptionPane.showConfirmDialog(j,"RESTART THE GAME");
        }     
        if(i==0)
        {
            s="";
            count=0;
            flag=false;
            Color color=null;
            for (JButton jb11 : jb1) {
                jb11.setText("");
                jb11.setBackground(color);
                jb11.setEnabled(true);
            }
            j1.setVisible(true);
            j2.setText("");
            j3.setText("");
        }
        else if(i==1)
            System.exit(0);
        else if(i==2)
            for (JButton jb11 : jb1) 
                jb11.setEnabled(false);
    }
}
