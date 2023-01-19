package v1.presentation;

import java.util.List;
import java.util.Optional;

import v1.data.entities.CategoryEntity;
import v1.domain.repositories.CategoryRepository;

public class Test {
    CategoryRepository repository = new CategoryRepository();

    public void startTest() {
        List<CategoryEntity> categoryList = repository.getAllCategories();
        Optional<CategoryEntity> category = repository.getCategoryById(2);

        if(!categoryList.isEmpty()) {
            for(CategoryEntity ent: categoryList) {
                System.out.println("cat name: " + ent.getName());
            }
        }
        if(category.isPresent()) {
            System.out.println("search cat name: " + category.get().getName());
        }
    }
}
