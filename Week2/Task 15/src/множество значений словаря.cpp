set<string> BuildMapValuesSet(const map<int, string>& m)
{
    set<string> huy;
    for(auto& c : m)
    {
        huy.insert(c.second);
    }
    return huy;
}
