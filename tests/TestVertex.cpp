//
// Created by Danial Dervovic on 05/04/2017.
//

#include "gtest/gtest.h"
#include "Vertex.h"

TEST(vertex_test, repeat_edge) {

    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex::add_edge(v1, v2);
    ASSERT_ANY_THROW(Vertex::add_edge(v1, v2));
    Vertex v3 = Vertex(3);
    ASSERT_ANY_THROW(Vertex::remove_edge(v1, v3));

}

TEST(vertex_test, neighbourhood){

    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);

    Vertex::add_edge(v1, v2);
    Vertex::add_edge(v2, v3);

    ASSERT_EQ(v1.get_neighbours_string(), "2 ");
    ASSERT_EQ(v2.get_neighbours_string(), "1 3 ");
    ASSERT_EQ(v3.get_neighbours_string(), "2 ");
}

TEST(vertex_test, is_neighbour) {

    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);

    Vertex::add_edge(v1, v2);
    Vertex::add_edge(v2, v3);

    ASSERT_TRUE(v1.is_neighbour(v2));
    ASSERT_TRUE(v2.is_neighbour(v1));
    ASSERT_TRUE(v2.is_neighbour(v3));
    ASSERT_TRUE(v3.is_neighbour(v2));

    ASSERT_FALSE(v1.is_neighbour(v3));
    ASSERT_FALSE(v3.is_neighbour(v1));
}

TEST(vertex_test, num_neighbours_of_v_in_set) {

    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);

    Vertex::add_edge(v1, v2);
    Vertex::add_edge(v1, v3);
    Vertex::add_edge(v2, v4);

    std::vector<std::shared_ptr<Vertex>> test_set = {std::make_shared<Vertex>(v2), std::make_shared<Vertex>(v3), std::make_shared<Vertex>(v4)};
    ASSERT_EQ(v1.num_neighbours_of_v_in_set(test_set), 2);

}

TEST(vertex_test, is_member) {

    Vertex v1 = Vertex(1);
    Vertex v2 = Vertex(2);
    Vertex v3 = Vertex(3);
    Vertex v4 = Vertex(4);

    std::vector<Vertex> test_set = {v2, v3, v4};

    ASSERT_TRUE(v2.is_member(test_set));
    ASSERT_FALSE(v1.is_member(test_set));
}


