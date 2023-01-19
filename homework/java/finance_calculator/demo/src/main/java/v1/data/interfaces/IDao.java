package v1.data.interfaces;

import java.util.List;
import java.util.Optional;

public interface IDao<T> {
    Optional<T> getById(long id);

    List<T> getAll();

    void save(T t);

    void update(T t, String[] params);

    void delete(T t);
}