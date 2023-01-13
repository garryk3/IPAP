package v1.domain.repositories;

import java.util.List;

import v1.data.dao.CategoryDao;
import v1.data.dao.DaoFactory;
import v1.data.entities.CategoryEntity;

public class CategoryRepository {
    private CategoryDao categoryDao = DaoFactory.getInstance().getCategoryDao();

    public List<CategoryEntity> getAllCategories() {
        return categoryDao.getAll();
    }
}
