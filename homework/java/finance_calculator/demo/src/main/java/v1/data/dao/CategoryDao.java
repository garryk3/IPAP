package v1.data.dao;

import java.util.List;
import java.util.Optional;

import v1.data.entities.CategoryEntity;
import v1.data.interfaces.IDao;
import v1.data.interfaces.IDatabase;

public class CategoryDao implements IDao<CategoryEntity> {
    private final IDatabase dbService;

    CategoryDao(IDatabase db) {
        dbService = db;
    }

    @Override
    public Optional<CategoryEntity> get(long id) {
        dbService.getClass(); // test
        return Optional.empty();
    }

    @Override
    public List<CategoryEntity> getAll() {
        return null;
    }

    @Override
    public void save(CategoryEntity t) {
    }

    @Override
    public void update(CategoryEntity t, String[] params) {}

    @Override
    public void delete(CategoryEntity t) {
    }

}
