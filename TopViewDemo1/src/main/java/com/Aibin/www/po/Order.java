package com.Aibin.www.po;

import java.util.Objects;

public class Order {
    private Integer id;
    private String filmName;
    private String  userName;
    private String seat;
    private String price;
    private String scene;

    public Order() {
    }

    public Order(Integer id, String filmName, String userName, String seat, String price, String scene) {
        this.id = id;
        this.filmName = filmName;
        this.userName = userName;
        this.seat = seat;
        this.price = price;
        this.scene = scene;
    }

    @Override
    public String toString() {
        return "Order{" +
                "id=" + id +
                ", filmName='" + filmName + '\'' +
                ", userName='" + userName + '\'' +
                ", seat='" + seat + '\'' +
                ", price='" + price + '\'' +
                ", scene='" + scene + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Order order = (Order) o;
        return Objects.equals(id, order.id) && Objects.equals(filmName, order.filmName) && Objects.equals(userName, order.userName) && Objects.equals(seat, order.seat) && Objects.equals(price, order.price) && Objects.equals(scene, order.scene);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, filmName, userName, seat, price, scene);
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getFilmName() {
        return filmName;
    }

    public void setFilmName(String filmName) {
        this.filmName = filmName;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getSeat() {
        return seat;
    }

    public void setSeat(String seat) {
        this.seat = seat;
    }

    public String getPrice() {
        return price;
    }

    public void setPrice(String price) {
        this.price = price;
    }

    public String getScene() {
        return scene;
    }

    public void setScene(String scene) {
        this.scene = scene;
    }
}
