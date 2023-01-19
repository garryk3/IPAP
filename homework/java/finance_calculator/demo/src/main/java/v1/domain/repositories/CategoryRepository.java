package v1.domain.repositories;

import java.util.List;
import java.util.Optional;

import v1.data.dao.DaoFactory;
import v1.data.entities.CategoryEntity;
import v1.data.interfaces.IDao;

public class CategoryRepository {
    private IDao<CategoryEntity> categoryDao = DaoFactory.getInstance().getCategoryDao();

    public List<CategoryEntity> getAllCategories() {
        return categoryDao.getAll();
    }

    public Optional<CategoryEntity> getCategoryById(int id) {
        return categoryDao.getById(id);
    }
}
