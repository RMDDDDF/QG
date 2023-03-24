package aibin;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class JDBCUtil_Connection {

    private static String URL="jdbc:mysql://localhost:3306/itcast";
    //数据库用户名
    private static String USER = "root";
    //用户密码
    private static String PASSWORD = "123456";
    //由于只执行一次所以加上static

    //获取数据库连接对象
    public static Connection open () {
        //数据库连接对象
        Connection conn = null;
        //获取连接并捕获异常
        try {
            //数据库驱动字符串
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection(URL, USER, PASSWORD);
            //判断是否成功连接
            if (null != conn) {
                System.out.println("成功！");
            } else {
                System.out.println("失败！");
            }
        } catch (Exception e) {
            e.printStackTrace();   //处理异常
        }
        return conn;   //返回连接对象
    }

    //关闭数据库连接
    public static void close (ResultSet rs, PreparedStatement pre, Connection conn){
        //若数据库连接对象不为空，否则关闭
        if (rs != null) {
            try {
                rs.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        //若PrepareStatement对象不为空，否则关闭
        if (pre != null) {
            try {
                pre.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        //若结果集对象不为空，否则关闭
        if (conn != null) {
            try {
                conn.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
