package com.Aibin.www.po;

import java.util.Objects;

public class Film {
    private Integer id;
    private String name;
    private String director;
    private String star;
    private String time;
    private String price;
    private String type;

    public Film() {
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Film film = (Film) o;
        return Objects.equals(id, film.id) && Objects.equals(name, film.name) && Objects.equals(director, film.director) && Objects.equals(star, film.star) && Objects.equals(time, film.time) && Objects.equals(price, film.price) && Objects.equals(type, film.type);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name, director, star, time, price, type);
    }

    @Override
    public String toString() {
        return "Film{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", director='" + director + '\'' +
                ", star='" + star + '\'' +
                ", time='" + time + '\'' +
                ", price='" + price + '\'' +
                ", type='" + type + '\'' +
                '}';
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDirector() {
        return director;
    }

    public void setDirector(String director) {
        this.director = director;
    }

    public String getStar() {
        return star;
    }

    public void setStar(String star) {
        this.star = star;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public String getPrice() {
        return price;
    }

    public void setPrice(String price) {
        this.price = price;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public Film(Integer id, String name, String director, String star, String time, String price, String type) {
        this.id = id;
        this.name = name;
        this.director = director;
        this.star = star;
        this.time = time;
        this.price = price;
        this.type = type;
    }
}
