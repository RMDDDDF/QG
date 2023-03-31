package com.Aibin.request;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet(value = "/req1")
public class requestDemo1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        // String getMethod()：获取请求方式： GET
        String method = request.getMethod();
        System.out.println(method);//GET
        // String getContextPath()：获取虚拟目录(项目访问路径)：
        String contextPath = request.getContextPath();
        System.out.println(contextPath);
        // StringBuffer getRequestURL(): 获取URL(统一资源定位符)：http://localhost:8080/request-demo/req1
        StringBuffer url = request.getRequestURL();
        System.out.println(url.toString());
        // String getRequestURI()：获取URI(统一资源标识符)： /com.Aibin.mapper.request-demo/req1
        String uri = request.getRequestURI();
        System.out.println(uri);
        // String getQueryString()：获取请求参数（GET方式）： username=zhangsan
        String queryString = request.getQueryString();
        System.out.println(queryString);


        //------------
        // 获取请求头：user-agent: 浏览器的版本信息
        String agent = request.getHeader("user-agent");
        System.out.println(agent);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //获取post 请求体：请求参数

        //1. 获取字符输入流
        BufferedReader br = request.getReader();
        //2. 读取数据
        String line = br.readLine();
        System.out.println(line);
    }
}
