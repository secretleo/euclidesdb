#pragma once

#include <unordered_map>
#include <string>

#include "torchmanager.hpp"
#include "databasemanager.hpp"


class SearchEngine
{
public:
    typedef std::shared_ptr<SearchEngine> SearchEnginePtr;

    SearchEngine(const TorchManager::TorchManagerPtr &torch_manager,
                 const DatabaseManager::DatabaseManagerPtr &database_manager);
    virtual void setup() = 0;

    virtual void search(const std::string &model_name,
                        const torch::Tensor &features_tensor,
                        int top_k, std::vector<int> *top_ids,
                        std::vector<float> *distances) = 0;

protected:
    TorchManager::TorchManagerPtr mTorchManager;
    DatabaseManager::DatabaseManagerPtr mDatabaseManager;
};



