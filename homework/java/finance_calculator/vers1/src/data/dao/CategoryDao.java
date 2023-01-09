package data.dao;

import java.util.List;
import java.util.Optional;

import data.entities.CategoryEntity;
import data.interfaces.IDao;

public class CategoryDao implements IDao<CategoryEntity> {

    @Override
    public Optional<CategoryEntity> get(long id) {
        // TODO Auto-generated method stub
        return Optional.empty();
    }

    @Override
    public List<CategoryEntity> getAll() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public void save(CategoryEntity t) {
        // TODO Auto-generated method stub

    }

    @Override
    public void update(CategoryEntity t, String[] params) {
        // TODO Auto-generated method stub

    }

    @Override
    public void delete(CategoryEntity t) {
        // TODO Auto-generated method stub

    }

}
