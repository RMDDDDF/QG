package aibin;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Scanner;

public class JDBCUtil {

    //在MySQL中创建用户信息表
    /*
    CREATE TABLE user_info(
            id int not null auto_increment comment "编号",
            user_name varchar(20) not null comment "用户名",
            age int not null comment "年龄",
            gender char(1) not null comment "性别",
            primary key(id)
)comment="用户信息表",
     */

    /*
    添加数据
     */
    public static void insert(Scanner sc) throws Exception{
        Connection conn = JDBCUtil_Connection.open();
        String sql="insert into user_info(user_name,age,gender) values(?,?,?)";
        PreparedStatement pre = conn.prepareStatement(sql);
        System.out.println("请输入用户名：");
        pre.setString(1,sc.next());
        System.out.println("请输入用户年龄：");
        pre.setInt(2,sc.nextInt());
        System.out.println("请输入用户性别：");
        pre.setString(3,sc.next());
        pre.executeUpdate();//执行语句
        System.out.println("插入成功！");

        JDBCUtil_Connection.close(null,pre,conn);
    }

    /*
    查询数据
     */
    public static void select() throws Exception {
        Connection conn = JDBCUtil_Connection.open();
        String sql = "select * from user_info";
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery(sql);
        System.out.println("\n用户信息表");
        System.out.println("编号\t用户名\t年龄\t性别");
        while (rs.next()) {
            System.out.print(rs.getInt("id") + "\t");
            System.out.print(rs.getString("user_name") + "\t\t");
            System.out.print(rs.getInt("age") + "\t");
            System.out.println(rs.getString("gender"));
        }
        //关闭资源
        rs.close();
        stmt.close();
        conn.close();
    }

        /*
        修改数据
         */
    public static void update(Scanner sc) throws Exception{
        Connection conn = JDBCUtil_Connection.open();
        String sql="update user_info set user_name=?,age=?,gender=? where id=?";
        PreparedStatement pre = conn.prepareStatement(sql);
        System.out.println("请输入修改后的用户名：");
        pre.setString(1,sc.next());
        System.out.println("请输入修改后的用户年龄：");
        pre.setInt(2,sc.nextInt());
        System.out.println("请输入修改后的用户性别：");
        pre.setString(3,sc.next());
        System.out.println("请输入要修改的用户id：");
        pre.setInt(4,sc.nextInt());
        pre.executeUpdate();
        System.out.println("修改成功！");

        JDBCUtil_Connection.close(null,pre,conn);
    }


    public static void delete(Scanner sc) throws Exception {
        Connection conn = JDBCUtil_Connection.open();
        String sql = "delete from user_info where id=?";
        PreparedStatement pre = conn.prepareStatement(sql);
        System.out.println("请输入要删除的用户id：");
        pre.setInt(1, sc.nextInt());
        pre.executeUpdate();
        System.out.println("删除成功！");

        JDBCUtil_Connection.close(null, pre, conn);

    }

    public static void main(String[] args) throws Exception {
       Scanner sc = new Scanner(System.in);
    
    }


}
