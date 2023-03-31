package com.Aibin.mapper;

import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import com.Aibin.pojo.User;

public interface UserMapper {

    /*
    查询用户对象的方法
     */
    @Select("select * from tb_user where username = #{username} and password = #{password}")
    User select(@Param("username") String username,@Param("password")String password);

}
