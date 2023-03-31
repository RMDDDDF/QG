package com.Aibin.request;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@WebServlet(value = "/req3")
public class requestDemo3 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //2. 获取username
        String username = request.getParameter("username");

        //先对乱码数据进行编码：转为字节数组,再解码
        username  = new String(username.getBytes(StandardCharsets.ISO_8859_1),StandardCharsets.UTF_8);

        System.out.println("username："+username);

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //设置字符输入流的编码
        request.setCharacterEncoding("UTF-8");
        //获取username
        String username = request.getParameter("username");
        System.out.println("username："+username);

    }
}
