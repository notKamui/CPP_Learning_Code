//#include "Box.h"
//
//#include <iostream>
//
//int main()
//{
//    std::cout << "box1 block begin" << std::endl;
//    {
//        Box box1 { "c1" };
//    }
//    std::cout << "box1 block end" << std::endl;
//    std::cout << "----------------" << std::endl;
//    std::cout << "box2 block begin" << std::endl;
//    {
//        Box box2 { "c2" };
//    }
//    std::cout << "box2 block end" << std::endl;
//    std::cout << "----------------" << std::endl;
//
//    std::cout << "Main begin" << std::endl;
//    Box* box = new Box("gift");
//    std::cout << box->get_content().name << std::endl;
//    delete box;
//    std::cout << "Main end" << std::endl;
//
//    std::cout << "----------------" << std::endl;
//
//    std::cout << "Main start" << std::endl;
//    Box*    box2    = new Box("gift");
//    Content content = box2->get_content();
//    std::cout << content.name << std::endl;
//    delete box2;
//    content.name = "chocolate";
//    std::cout << content.name << std::endl;
//    std::cout << "Main end" << std::endl;
//
//    std::cout << "----------------" << std::endl;
//
//    std::cout << "Main start" << std::endl;
//    Box*     box3         = new Box("gift");
//    Content& content_ref = box3->get_content();
//    std::cout << content_ref.name << std::endl;
//    delete box3;
//    content_ref.name = "chocolate";
//    std::cout << content_ref.name << std::endl;
//    std::cout << "Main end" << std::endl;
//
//    return 0;
//}

#include <string>
#include <vector>
#include <memory>

struct Resource
{
    Resource(const std::string& content)
        : _content { content }
    {}

    std::string _content;
};

// Index objects of type Resource and handle their lifespans.
class ResourceManager
{
public:
    // Create a new resource.
    // Return the index where the resource was created.
    size_t create(const std::string& content)
    {
        _resources.emplace_back(std::make_unique<Resource>(content));
        return _resources.size() - 1;
    }

    // Destroy the resource at the given index.
    // The other elements keep the same index, we do not reorganize the array.
    void destroy(size_t index)
    {
        _resources[index].reset();
    }

    // Take the ownership of an existing resource.
    // Return the index where the resource was placed.
    size_t acquire(std::unique_ptr<Resource> resource)
    {
        _resources.emplace_back(std::move(resource));
        return _resources.size() - 1;
    }

    // Transfer the resource at the given index to the caller.
    std::unique_ptr<Resource> yield(size_t index)
    {
        return std::move(_resources[index]);
    }

    // Provide access to the resource at the given index.
    Resource& get(size_t index) const
    {
        return *_resources[index];
    }

private:
    std::vector<std::unique_ptr<Resource>> _resources;
};
