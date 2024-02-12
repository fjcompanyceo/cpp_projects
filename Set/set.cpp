#include<iostream>
#include<set>
#include<string>


template <typename T>
void print_set(std::set<T>& inset){
    for(const auto& elem: inset){
        std::cout << elem << std::endl;
    }
}

class Todo {
    int priority;
    std::string job_desc;
    friend std::ostream & operator<< (std::ostream & o, const Todo& in);
    
    public: 
        Todo(int priority, std::string job_desc)
            : priority(priority), job_desc(job_desc) {}
        bool operator<(const Todo& in) const {
            if(priority == in.priority){
                return job_desc < in.job_desc;
            }
            return (priority > in.priority);

        }


};

std::ostream & operator<< (std::ostream & o, const Todo& in){
    o << "priority:" << in.priority << "job desc:" << in.job_desc << std::endl;
    return o;
}

int main() {
    std::set<Todo> todos;
    todos.insert(Todo(1,"abc"));
    todos.insert(Todo(2,"abc"));
    todos.insert(Todo(1,"bc"));
    todos.insert(Todo(1,"efg"));
    todos.insert(Todo(3,"cde"));
    todos.insert(Todo(3,"bc"));

    print_set(todos);
    todos.erase(todos.find(Todo(1,"abc")));

    std::cout << "====================== print changed result ======================= \n" << std::endl;
    print_set(todos);

    return 0;
}