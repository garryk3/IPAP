package v1.data.dao;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import v1.data.entities.CategoryEntity;
import v1.data.interfaces.IDao;
import v1.data.interfaces.IDatabase;

public class CategoryDao implements IDao<CategoryEntity> {
    private final IDatabase dbService;
    private List<CategoryEntity> categoryEntities = new ArrayList<CategoryEntity>();

    CategoryDao(IDatabase db) {
        dbService = db;
    }

    private CategoryEntity createCategoryFromResultSet(ResultSet set) throws SQLException {
        return new CategoryEntity(
            set.getInt("id"), 
            set.getString("type"), 
            set.getString("name")
        );
    }

    @Override
    public Optional<CategoryEntity> getById(long id) {
        ResultSet set = dbService.executeQuery("SELECT id, type, name FROM categories WHERE id = " + id);

        try {
            while(set.next()) {
                return Optional.of(createCategoryFromResultSet(set));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return Optional.empty();
    }

    @Override
    public List<CategoryEntity> getAll() {
        if(!categoryEntities.isEmpty()) {
            return categoryEntities;
        }
        ResultSet set = dbService.executeQuery("SELECT id, type, name FROM categories");
        try {
            while(set.next()) {
                categoryEntities.add(createCategoryFromResultSet(set));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return categoryEntities;
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
