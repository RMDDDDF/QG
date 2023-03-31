package com.Aibin;

import com.Aibin.mapper.UserMapper;
import com.Aibin.pojo.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.net.URLEncoder;

@WebServlet(value = "/loginDemo")
public class loginDemo extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //获取用户及密码
        String username = request.getParameter("username");
        System.out.println(username);
        String password = request.getParameter("password");
        //mybatis
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        SqlSession sqlSession = sqlSessionFactory.openSession();

        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        User user = userMapper.select(username, password);

        sqlSession.close();


        response.setContentType("text/html;charset=utf-8");
        PrintWriter writer = response.getWriter();
        //判断是否为null
        if(user != null)
        {
            System.out.println("Success");
            //成功，状态码为200
            response.setStatus(200);
            writer.write("即将跳转至哔哩哔哩~~");
            //状态码302，跳转网站
            response.sendRedirect("https://www.bilibili.com");

        }
        else
        {
            System.out.println("Fail");
            //失败，返回404
            response.sendError(404, "NO Found！");

        }


    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
