package v1.data.dao;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import v1.data.entities.FinanceItemEntity;
import v1.data.interfaces.IDao;
import v1.data.interfaces.IDatabase;

public class FinanceItemDao implements IDao<FinanceItemEntity> {
    private final IDatabase dbService;
    private List<FinanceItemEntity> financeItemEntities = new ArrayList<FinanceItemEntity>();

    FinanceItemDao(IDatabase db) {
        dbService = db;
    }

    private FinanceItemEntity createFinanceItemFromResultSet(ResultSet set) throws SQLException {
        return new FinanceItemEntity(
            set.getInt("id"), 
            set.getString("currency"), 
            set.getString("name"),
            set.getString("type"),
            set.getInt("prices")
        );
    }

    @Override
    public Optional<FinanceItemEntity> getById(long id) {
        ResultSet set = dbService.executeQuery("SELECT id, type, name FROM finance_items WHERE id = " + id);

        try {
            while(set.next()) {
                return Optional.of(createFinanceItemFromResultSet(set));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return Optional.empty();
    }

    @Override
    public List<FinanceItemEntity> getAll() {
        if(!financeItemEntities.isEmpty()) {
            return financeItemEntities;
        }
        ResultSet set = dbService.executeQuery("SELECT id, type, name FROM categories");
        try {
            while(set.next()) {
                financeItemEntities.add(createFinanceItemFromResultSet(set));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return financeItemEntities;
    }

    @Override
    public void save(FinanceItemEntity t) {
    }

    @Override
    public void update(FinanceItemEntity t, String[] params) {}

    @Override
    public void delete(FinanceItemEntity t) {
    }
}
