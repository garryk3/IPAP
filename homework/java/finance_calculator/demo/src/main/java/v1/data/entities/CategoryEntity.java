package v1.data.entities;

import v1.data.interfaces.IEntity;

public class CategoryEntity implements IEntity {
    private int id;
    private String type;
    private String name;

    public CategoryEntity(int id, String type, String name) {
        this.id = id;
        this.type = type;
        this.name = name;
    }

    @Override
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }
}
